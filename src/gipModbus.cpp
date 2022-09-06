/*
 * gipModbus.cpp
 *
 *  Created on: 29 Aug 2022
 *      Author: noyan
 */

#include "gipModbus.h"


gipModbus::gipModbus(std::string ip, int port) : mb(ip, port) {
	this->ip = ip;
	this->port = port;
	slaveid = 1;
	holdingregnum = 16;
	read_holding_regs = new uint16_t[holdingregnum];
}

gipModbus::~gipModbus() {
	delete read_holding_regs;
}

std::string gipModbus::getIp() {
	return ip;
}

int gipModbus::getPort() {
	return port;
}

void gipModbus::setSlaveId(int id) {
	slaveid = id;
	mb.modbus_set_slave_id(slaveid);
}

int gipModbus::getSlaveId() {
	return slaveid;
}

void gipModbus::connect() {
	gLogi("gipModbus") << "Please wait, connecting...";
	mb.modbus_connect();
	gLogi("gipModbus") << "Connected!";
}

void gipModbus::close() {
	mb.modbus_close();
}

bool gipModbus::isConnected() {
	return mb.is_connected();
}

void gipModbus::createHoldingRegisters(int num) {
	holdingregnum = num;
//	if(read_holding_regs) delete read_holding_regs;
	read_holding_regs = new uint16_t[holdingregnum];
}

int gipModbus::getHoldingRegNum() {
	return holdingregnum;
}

void gipModbus::setRegisterValue(uint16_t address, const uint16_t &value) {
    mb.modbus_write_register(address, value);
}

void gipModbus::readHoldingRegisters(uint16_t address) {
    mb.modbus_read_holding_registers(address, holdingregnum, read_holding_regs);
}

uint16_t gipModbus::getHoldingRegister(int regNo) {
	return read_holding_regs[regNo];
}
