# copelike_c_neat_ia
a simple reproduction of the software copelia but only with precise 2d maps to be able to train an ia to drive a car

possible command are : 
command                   value range           answer type
START_SIMULATION             -                       (1)
STOP_SIMULATION              -                       (1)
CAR_FORWARD:float          [0;1]                     (1)
CAR_BACKWARDS:float        [0;1]                     (1)
WHEELS_DIR:float           [-1;1]                    (1)
GET_INFO_LIDAR               -                       (2)
GET_CURRENT_SPEED            -                       (3)
GET_CURRENT_WHEELS           -                       (3)
CYCLE_WAIT:int          [0; INT_MAX]                 (3)
GET_CAR_SPEED_MAX            -                       (3)
GET_CAR_SPEED_MIN            -                       (3)
GET_INFO_SIMTIME             -                       (4)
