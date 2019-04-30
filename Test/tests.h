//
// Created by Роман Климовицкий on 07.04.2018.
//

#ifndef CARD_SERVICE_SYSTEM_TESTS_H
#define CARD_SERVICE_SYSTEM_TESTS_H

#include <gtest/gtest.h>
#include "Card/Card.h"
#include "Microservices/ServiceFactory.h"
#include "Microservices/BankService.h"
#include "Microservices/HealthInsuranceService.h"
#include "Microservices/PassportOfficeService.h"
#include "Terminal/Terminal.h"
#include "Utils/Date.h"
#include "Utils/Policy.h"
#include "Utils/Passport.h"


class BankServiceTest : public ::testing::Test {
protected:
    std::shared_ptr<BankService> bankService;

    void SetUp() {
        bankService = std::make_shared<BankService>();
        std::cout << "BANK SERVICE TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "BANK SERVICE TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(BankServiceTest, BalanceGettingTest) {
    EXPECT_EQ(bankService->getBalance(0), 0);
}


class PolicyTest : public ::testing::Test {
protected:
    std::shared_ptr<Policy> policy;

    void SetUp() {
        policy = std::make_shared<Policy>();
        std::cout << "POLICY TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "POLICY TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(PolicyTest, GetterTest) {
    EXPECT_EQ(policy->getNumber(), "0000000000000000");
    EXPECT_EQ(policy->getInsuranceDate(), Date());
    EXPECT_EQ(policy->getInsuranceCompany(), "Company");
}


class HealthInsuranceServiceTest : public ::testing::Test {
protected:
    std::shared_ptr<IHealthInsuranceService> healthInsuranceService;
    std::shared_ptr<IHealthInsuranceService> cachedHealthInsuranceService;

    void SetUp() {
        healthInsuranceService = std::make_shared<HealthInsuranceService>();
        cachedHealthInsuranceService = std::make_shared<CachedHealthInsuranceService>();
        std::cout << "HEALTH INSURANCE SERVICE TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "HEALTH INSURANCE SERVICE TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(HealthInsuranceServiceTest, StandardServiceTest) {
    std::shared_ptr<Policy> receivedPolicy = healthInsuranceService->getPolicy(0);
    std::shared_ptr<Policy> rightPolicy = std::make_shared<Policy>();
    EXPECT_EQ(*receivedPolicy, *rightPolicy);
}

TEST_F(HealthInsuranceServiceTest, CachedProxyTest) {
    std::shared_ptr<Policy> stdPolicy = healthInsuranceService->getPolicy(0);
    std::shared_ptr<Policy> cachedPolicy = cachedHealthInsuranceService->getPolicy(0);
    EXPECT_EQ(*stdPolicy, *cachedPolicy);
}


class PassportTest : public ::testing::Test {
protected:
    std::shared_ptr<Passport> passport;

    void SetUp() {
        passport = std::make_shared<Passport>();
        std::cout << "PASSPORT TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "PASSPORT TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(PassportTest, GetterTest) {
    EXPECT_EQ(passport->getFirstName(), "First Name");
    EXPECT_EQ(passport->getLastName(), "Last Name");
    EXPECT_EQ(passport->getBirthDate(), Date());
}


class PassportOfficeServiceTest : public ::testing::Test {
protected:
    std::shared_ptr<IPassportOfficeService> passportOfficeService;
    std::shared_ptr<IPassportOfficeService> cachedPassportOfficeService;

    void SetUp() {
        passportOfficeService = std::make_shared<PassportOfficeService>();
        cachedPassportOfficeService = std::make_shared<CachedPassportOfficeService>();
        std::cout << "PASSPORT OFFICE SERVICE TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "PASSPORT OFFICE SERVICE TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(PassportOfficeServiceTest, StandardServiceTest) {
    std::shared_ptr<Passport> receivedPassport = passportOfficeService->getPassport(0);
    std::shared_ptr<Passport> rightPassport = std::make_shared<Passport>();
    EXPECT_EQ(*receivedPassport, *rightPassport);
}

TEST_F(PassportOfficeServiceTest, CachedProxyTest) {
    std::shared_ptr<Passport> stdPassport = passportOfficeService->getPassport(0);
    std::shared_ptr<Passport> cachedPassport = cachedPassportOfficeService->getPassport(0);
    EXPECT_EQ(*stdPassport, *cachedPassport);
}


class ServiceFactoryTest : public ::testing::Test {
protected:
    ServiceFactory factory;

    void SetUp() {
        std::cout << "SERVICE FACTORY TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "SERVICE FACTORY TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(ServiceFactoryTest, OutputTypeTest) {
    EXPECT_EQ(typeid(*factory.getBankService()), typeid(*std::make_shared<BankService>()));
    EXPECT_EQ(typeid(*factory.getHealthInsuranceService()), typeid(*std::make_shared<CachedHealthInsuranceService>()));
    EXPECT_EQ(typeid(*factory.getPassportOfficeService()), typeid(*std::make_shared<CachedPassportOfficeService>()));
}


class CardTest : public ::testing::Test {
protected:
    std::shared_ptr<Card> card;

    void SetUp() {
        card = std::make_shared<Card>();
        std::cout << "CARD TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "CARD TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(CardTest, GetterTest) {
    EXPECT_EQ(card->getId(), 0);
    EXPECT_EQ(card->getFirstName(), "First Name");
    EXPECT_EQ(card->getLastName(), "Last Name");
}


class TerminalTest : public ::testing::Test {
protected:
    std::shared_ptr<Terminal> terminal;

    void SetUp() {
        std::cout << "TERMINAL TEST SET UP" << std::endl;
    }

    void TearDown() {
        std::cout << "TERMINAL TEST TEARED DOWN" << std::endl;
    }
};

TEST_F(TerminalTest, DefaultConstructing) {
    terminal = std::make_shared<Terminal>();
    EXPECT_EQ(terminal->getCard(), nullptr);
}

TEST_F(TerminalTest, ConstructingWithParameterTest) {
    terminal = std::make_shared<Terminal>(std::make_shared<Card>());
    EXPECT_EQ(*terminal->getCard(), Card());
}

TEST_F(TerminalTest, CardTest) {
    terminal = std::make_shared<Terminal>();
    terminal->insertCard();
    EXPECT_EQ(*terminal->getCard(), Card());
    terminal->returnCard();
    EXPECT_EQ(terminal->getCard(), nullptr);
}


#endif //CARD_SERVICE_SYSTEM_TESTS_H
