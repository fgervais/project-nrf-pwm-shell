# Project Management

## Init

```bash
mkdir project-nrf-pwm-shell
cd project-nrf-pwm-shell
docker run --rm -u $(id -u):$(id -g) -v $(pwd):/new -w /new -e ZEPHYR_BASE="" nordicplayground/nrfconnect-sdk:v2.4-branch \
        bash -c "west init -m https://github.com/fgervais/project-nrf-pwm-shell.git . && west update"
```

## Build

```bash
cd application
docker compose run --rm nrf west build -b pink_panda -s app
```

## menuconfig

```bash
cd application
docker compose run --rm nrf west build -b pink_panda -s app -t menuconfig
```

## Clean

```bash
cd application
rm -rf build/
```

## Update

```bash
cd application
docker compose run --rm nrf west update
```

## Flash

### nrfjprog
```bash
cd application
docker compose -f docker-compose.yml -f docker-compose.device.yml \
        run nrf west flash
```

### pyocd
```bash
cd application
pyocd flash -e sector -t nrf52840 -f 4000000 build/zephyr/zephyr.hex
```
