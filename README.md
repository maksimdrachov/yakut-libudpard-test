# Yakut-Libudpard test

## Test 1: Yakut - Yakut service call

In first terminal window:

```
export UAVCAN__NODE__ID=42
export UAVCAN__UDP__IFACE=127.0.0.1
export UAVCAN__SUB__TEMPERATURE_SETPOINT__ID=2345
export UAVCAN__SUB__TEMPERATURE_MEASUREMENT__ID=2346
export UAVCAN__PUB__HEATER_VOLTAGE__ID=2347
export UAVCAN__SRV__LEAST_SQUARES__ID=123
export UAVCAN__DIAGNOSTIC__SEVERITY=2

python demo_app.py
```

In second terminal window:

```
export UAVCAN__UDP__IFACE=127.0.0.1
export UAVCAN__NODE__ID=43
export CYPHAL_PATH="./public_regulated_data_types;./custom_data_types"
y call 42 123:sirius_cyber_corp.PerformLinearLeastSquaresFit 'points: [{x: 10, y: 3}, {x: 20, y: 4}]'
# Result should be: 123: {slope: 0.1, y_intercept: 2.0}
```

## Test 2: Yakut - libudpard service call

In first terminal window:

```
export UAVCAN__NODE__ID=42
export UAVCAN__UDP__IFACE=127.0.0.1
export UAVCAN__SUB__TEMPERATURE_SETPOINT__ID=2345
export UAVCAN__SUB__TEMPERATURE_MEASUREMENT__ID=2346
export UAVCAN__PUB__HEATER_VOLTAGE__ID=2347
export UAVCAN__SRV__LEAST_SQUARES__ID=123
export UAVCAN__DIAGNOSTIC__SEVERITY=2

python demo_app.py
```

In second terminal window:

```
cd libudpard
mkdir build
cmake ..
make
./MyExecutable
```
