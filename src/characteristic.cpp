#include "characteristic.h"

Main_Characteristic& Characteristic::get_Main_Characteristic() {
    return this->_main_characteristic;

}
void Characteristic::set_Main_Characteristic(
	float correct_life_point,
	float max_life_point,
	float correct_mana_point,
	float max_mana_point,
	float correct_energi_point,
	float max_energi_point,
	float move_speed,
	float min_damage,
	float max_damage,
	float power_attack,
	float power_magic,
	float phisical_defense,
	float magic_defense
) {

	this->_main_characteristic.correct_life_point = correct_life_point;
	this->_main_characteristic.max_life_point = max_life_point;
	this->_main_characteristic.correct_mana_point = correct_mana_point;
	this->_main_characteristic.max_mana_point = max_mana_point;
	this->_main_characteristic.correct_energi_point = correct_energi_point;
	this->_main_characteristic.max_energi_point = max_energi_point;
	this->_main_characteristic.move_speed = move_speed;
	this->_main_characteristic.min_damage = min_damage;
	this->_main_characteristic.max_damage = max_damage;
	this->_main_characteristic.power_attack = power_attack;
	this->_main_characteristic.power_magic = power_magic;
	this->_main_characteristic.phisical_defense = phisical_defense;
	this->_main_characteristic.magic_defense = magic_defense;

}

Physical_Defense_Characteristic& Characteristic::get_Physical_Defense_Characteristic() {
	return this->_physical_defense_characteristic;

}
void Characteristic::set_Physical_Defense_Characteristic(
	float crushingly_defense,
	float prickly_defense,
	float cutting_defense
) {

	this->_physical_defense_characteristic.crushingly_defense = crushingly_defense;
	this->_physical_defense_characteristic.prickly_defense = prickly_defense;
	this->_physical_defense_characteristic.cutting_defense = cutting_defense;

}

Magic_Defense_Characteristic& Characteristic::get_Magic_Defense_Characteristic() {
	return this->_magic_defense_characteristic;

}
void Characteristic::set_Magic_Defense_Characteristic(
	float fire_defense,
	float water_defense,
	float air_defense,
	float earth_defense
) {

	this->_magic_defense_characteristic.fire_defense = fire_defense;
	this->_magic_defense_characteristic.water_defense = water_defense;
	this->_magic_defense_characteristic.air_defense = air_defense;
	this->_magic_defense_characteristic.earth_defense = earth_defense;

}

Physical_Damage_Characteristic& Characteristic::get_Physical_Damage_Characteristic() {
	return this->_physical_damage_characteristic;

}

Magic_Damage_Characteristic& Characteristic::get_Magic_Damage_Characteristic() {
	return this->_magic_damage_characteristic;

}
void Characteristic::set_Magic_Damage_Characteristic(
	float fire_damage,
	float water_damage,
	float air_damage,
	float earth_damage
) {

	this->_magic_damage_characteristic.fire_damage = fire_damage;
	this->_magic_damage_characteristic.water_damage = water_damage;
	this->_magic_damage_characteristic.air_damage = air_damage;
	this->_magic_damage_characteristic.earth_damage = earth_damage;

}
