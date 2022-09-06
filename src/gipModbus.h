/*
 * gipModbus.h
 *
 *  Created on: 29 Aug 2022
 *      Author: noyan
 */

#ifndef SRC_GIPMODBUS_H_
#define SRC_GIPMODBUS_H_

#include "gBasePlugin.h"
#include "modbus.h"


class gipModbus : public gBasePlugin {
public:
	gipModbus(std::string ip, int port);
	virtual ~gipModbus();

	std::string getIp();
	int getPort();
	void setSlaveId(int id);
	int getSlaveId();

	void connect();
	void close();
	bool isConnected();

	void createHoldingRegisters(int num);
	int getHoldingRegNum();
	void setRegisterValue(uint16_t address, const uint16_t &value);
	void readHoldingRegisters(uint16_t address = 0);

	uint16_t getHoldingRegister(int regNo);

private:
	modbus mb;
	std::string ip;
	int port;
	int slaveid;
	uint16_t* read_holding_regs;
	int holdingregnum;
};

#endif /* SRC_GIPMODBUS_H_ */
