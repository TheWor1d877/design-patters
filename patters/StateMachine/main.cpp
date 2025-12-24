#include <filesystem>

#include "state_machine.h"
#include "states/pending_pay.h"
#include "states/paid.h"
#include "states/delivering.h"
#include "states/completed.h"
#include <iostream>

int main() {
    StateMachine sm(Status::PENDING_PAY);

    sm.map<Payed>(Status::PENDING_PAY, std::make_unique<Paid>());
    sm.map<Cancel>(Status::PENDING_PAY, std::make_unique<Completed>());
    sm.map<Deliver>(Status::PAID, std::make_unique<Delivering>());
    sm.map<Receive>(Status::DELIVERING, std::make_unique<Completed>());
    sm.map<Cancel>(Status::PAID, std::make_unique<Completed>());

    sm.process(Payed{});
    sm.process(Cancel{});

}