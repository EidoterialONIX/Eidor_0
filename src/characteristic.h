#pragma once

struct Main_Characteristic {

	float correct_life_point = 0.0f;
	float max_life_point = 0.0f;

	float correct_mana_point = 0.0f;
	float max_mana_point = 0.0f;
	
	float correct_energi_point = 0.0f;
	float max_energi_point = 0.0f;

	float move_speed = 0.0f;

	float min_damage = 0.0f;
	float max_damage = 0.0f;

	float power_attack = 0.0f;
	float power_magic = 0.0f;

	float phisical_defense = 0.0f;
	float magic_defense = 0.0f;

};

struct Physical_Defense_Characteristic {

	float crushingly_defense = 0.0f;
	float prickly_defense = 0.0f;
	float cutting_defense = 0.0f;

};
struct Magic_Defense_Characteristic {

	float fire_defense = 0.0f;
	float water_defense = 0.0f;
	float air_defense = 0.0f;
	float earth_defense = 0.0f;

};

struct Physical_Damage_Characteristic {

	float crushingly_damage = 0.0f;
	float prickly_damage = 0.0f;
	float cutting_damage = 0.0f;


};
struct Magic_Damage_Characteristic {

	float fire_damage = 0.0f;
	float water_damage = 0.0f;
	float air_damage = 0.0f;
	float earth_damage = 0.0f;

};

class Characteristic {
private:

	Main_Characteristic _main_characteristic;

	Physical_Defense_Characteristic _physical_defense_characteristic;
	Magic_Defense_Characteristic _magic_defense_characteristic;
	
	Physical_Damage_Characteristic _physical_damage_characteristic;
	Magic_Damage_Characteristic _magic_damage_characteristic;

public:

	Characteristic() = default;

	Main_Characteristic& get_Main_Characteristic();
	void set_Main_Characteristic(
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
	);

	Physical_Defense_Characteristic& get_Physical_Defense_Characteristic();
	void set_Physical_Defense_Characteristic(
		float crushingly_defense,
		float prickly_defense,
		float cutting_defense
	);

	Magic_Defense_Characteristic& get_Magic_Defense_Characteristic();
	void set_Magic_Defense_Characteristic(
		float fire_defense,
		float water_defense,
		float air_defense,
		float earth_defense
	);

	Physical_Damage_Characteristic& get_Physical_Damage_Characteristic();
	void set_Physical_Damage_Characteristic(
		float crushingly_damage,
		float prickly_damage,
		float cutting_damage
	) {

		this->_physical_damage_characteristic.crushingly_damage = crushingly_damage;
		this->_physical_damage_characteristic.prickly_damage = prickly_damage;
		this->_physical_damage_characteristic.cutting_damage = cutting_damage;

	}

	Magic_Damage_Characteristic& get_Magic_Damage_Characteristic();
	void set_Magic_Damage_Characteristic(
		float fire_damage,
		float water_damage,
		float air_damage,
		float earth_damage
	);

};