# NetMiddleware

This is middleware between frontend the service responsible for configuration management and the service responsible for dataplane management. The "NetMiddleware" project is part of a larger project called "yaNOS" (yet another Networking Operating System).

# Design
┌──────────────────┐                  ┌──────────────────┐                ┌────────────────────────┐
│                  │                  │                  │                │                        │
│                  │  JSON over HTTP  │                  │      RPC       │                        │
│    FlexConfig    ├──────────────────┤    Middleware    ├────────────────┤   SDK/SAI/ASIC/DPDK    │
│                  │                  │                  │                │ (Dataplane management) │
│                  │                  │                  │                │                        │
└────────┬─────────┘                  └──────────────────┘                └────────────────────────┘
         │
         │
         │ JSON                        Synchronizes state                  Program ASIC via SDK API,
         │ over                        beetween modules,                   SAI API or DPDK. It does
         │ HTTPS                       i.e. update VLAN                    not store any state
         │                             for ports in bundle
         │
   ┌─────┴──────┐                      Additionally it
   │            │                      synchronize the state
   │            │                      from other components
   │    User    │                      like nexthop checker,
   │            │                      RIB table (i.e. BGP
   │            │                      speaker), etc.
   └────────────┘
                                       This is also middleware
                                       to handle type of
                                       cables/connector
                                       (need FEC, enable AN,
                                       set preemphasis settings
                                       in PHY, etc.)

                                       Speaks with userspace
                                       daemons, like LACP,
                                       BGP

                                       When FlexConfig starts the
                                       transaction it should notify
                                       all of NetMiddeware components
                                       that the transaction has been
                                       started. When a component is 
                                       modyfing during the transaction
                                       it should create Memento (snapshot)
                                       of its internal state. When 
                                       FlexConfig notify a component about
                                       the error of transaction then it
                                       should process its action to the
                                       Hardware and restore its internal
                                       state from Memento. FlexConfig
                                       has to notify all components
                                       about finished transaction in order
                                       to delete Memento object by
                                       component.

# Project structure
## lib/
Under the lib/ directory there should be put all utils and interfaces file.
