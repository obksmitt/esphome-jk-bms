#pragma once

#include "esphome/core/component.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/switch/switch.h"
#include "esphome/components/jk_rs485_sniffer/jk_rs485_sniffer.h"

namespace esphome {
namespace jk_rs485_bms {

enum ProtocolVersion {
  PROTOCOL_VERSION_JK04,
  PROTOCOL_VERSION_JK02_24S,
  PROTOCOL_VERSION_JK02_32S,
};

class JkRS485Bms : public PollingComponent, public jk_rs485_sniffer::JkRS485SnifferDevice {
 public:
  void set_address(uint8_t address) { address_ = address; }

  void set_smart_sleep_time_sensor(sensor::Sensor *smart_sleep_time_sensor) {
    smart_sleep_time_sensor_ = smart_sleep_time_sensor;
  }
  void set_balancing_binary_sensor(binary_sensor::BinarySensor *balancing_binary_sensor) {
    balancing_binary_sensor_ = balancing_binary_sensor;
  }
  void set_balancing_sensor(sensor::Sensor *balancing_sensor) {
    balancing_sensor_ = balancing_sensor;
  } 
  void set_balancing_status_binary_sensor(binary_sensor::BinarySensor *balancing_status_binary_sensor) {
    balancing_status_binary_sensor_ = balancing_status_binary_sensor;
  }
  void set_precharging_status_binary_sensor(binary_sensor::BinarySensor *precharging_status_binary_sensor) {
    precharging_status_binary_sensor_ = precharging_status_binary_sensor;
  }
  void set_charging_status_binary_sensor(binary_sensor::BinarySensor *charging_status_binary_sensor) {
    charging_status_binary_sensor_ = charging_status_binary_sensor;
  }
  void set_discharging_status_binary_sensor(binary_sensor::BinarySensor *discharging_status_binary_sensor) {
    discharging_status_binary_sensor_ = discharging_status_binary_sensor;
  }
  void set_online_status_binary_sensor(binary_sensor::BinarySensor *online_status_binary_sensor) {
    online_status_binary_sensor_ = online_status_binary_sensor;
  }
  void set_heating_status_binary_sensor(binary_sensor::BinarySensor *heating_status_binary_sensor) {
    heating_status_binary_sensor_ = heating_status_binary_sensor;
  }   
  void set_cell_count_sensor(sensor::Sensor *cell_count_sensor) { cell_count_sensor_ = cell_count_sensor; }

  void set_balancing_switch_binary_sensor(binary_sensor::BinarySensor *balancing_switch_binary_sensor) {
    balancing_switch_binary_sensor_ = balancing_switch_binary_sensor;
  }

  void set_charging_binary_sensor(binary_sensor::BinarySensor *charging_binary_sensor) {
    charging_binary_sensor_ = charging_binary_sensor;
  }
  void set_charging_switch_binary_sensor(binary_sensor::BinarySensor *charging_switch_binary_sensor) {
    charging_switch_binary_sensor_ = charging_switch_binary_sensor;
  }

  void set_precharging_binary_sensor(binary_sensor::BinarySensor *precharging_binary_sensor) {
    precharging_binary_sensor_ = precharging_binary_sensor;
  }
  void set_precharging_switch_binary_sensor(binary_sensor::BinarySensor *precharging_switch_binary_sensor) {
    precharging_switch_binary_sensor_ = precharging_switch_binary_sensor;
  }  
  
  void set_discharging_binary_sensor(binary_sensor::BinarySensor *discharging_binary_sensor) {
    discharging_binary_sensor_ = discharging_binary_sensor;
  }
  void set_discharging_switch_binary_sensor(binary_sensor::BinarySensor *discharging_switch_binary_sensor) {
    discharging_switch_binary_sensor_ = discharging_switch_binary_sensor;
  }

  void set_dedicated_charger_switch_binary_sensor(binary_sensor::BinarySensor *dedicated_charger_switch_binary_sensor) {
    dedicated_charger_switch_binary_sensor_ = dedicated_charger_switch_binary_sensor;
  }

  void set_smart_sleep_voltage_sensor(sensor::Sensor *smart_sleep_voltage_sensor) {
    smart_sleep_voltage_sensor_ = smart_sleep_voltage_sensor;
  }
  void set_min_cell_voltage_sensor(sensor::Sensor *min_cell_voltage_sensor) {
    min_cell_voltage_sensor_ = min_cell_voltage_sensor;
  }
  void set_max_cell_voltage_sensor(sensor::Sensor *max_cell_voltage_sensor) {
    max_cell_voltage_sensor_ = max_cell_voltage_sensor;
  }
  void set_min_voltage_cell_sensor(sensor::Sensor *min_voltage_cell_sensor) {
    min_voltage_cell_sensor_ = min_voltage_cell_sensor;
  }
  void set_max_voltage_cell_sensor(sensor::Sensor *max_voltage_cell_sensor) {
    max_voltage_cell_sensor_ = max_voltage_cell_sensor;
  }
  void set_delta_cell_voltage_sensor(sensor::Sensor *delta_cell_voltage_sensor) {
    delta_cell_voltage_sensor_ = delta_cell_voltage_sensor;
  }
  void set_average_cell_voltage_sensor(sensor::Sensor *average_cell_voltage_sensor) {
    average_cell_voltage_sensor_ = average_cell_voltage_sensor;
  }
  void set_cell_voltage_sensor(uint8_t cell, sensor::Sensor *cell_voltage_sensor) {
    this->cells_[cell].cell_voltage_sensor_ = cell_voltage_sensor;
  }
  void set_cell_resistance_sensor(uint8_t cell, sensor::Sensor *cell_resistance_sensor) {
    this->cells_[cell].cell_resistance_sensor_ = cell_resistance_sensor;
  }
//  void set_temperature_temperature_sensor(uint8_t i, sensor::Sensor *temperature_temperature_sensor) {
//    this->temperatures_[i].temperature_sensor_ = temperature_temperature_sensor;
//  }  
  void set_temperature_sensor(uint8_t i, sensor::Sensor *temperature_sensor) {
    this->temperatures_[i].temperature_sensor_ = temperature_sensor;
  }    
  void set_power_tube_temperature_sensor(sensor::Sensor *power_tube_temperature_sensor) {
    power_tube_temperature_sensor_ = power_tube_temperature_sensor;
  }
  void set_temperature_sensor_1_sensor(sensor::Sensor *temperature_sensor_1_sensor) {
    temperature_sensor_1_sensor_ = temperature_sensor_1_sensor;
  }
  void set_temperature_sensor_2_sensor(sensor::Sensor *temperature_sensor_2_sensor) {
    temperature_sensor_2_sensor_ = temperature_sensor_2_sensor;
  }
  void set_total_voltage_sensor(sensor::Sensor *total_voltage_sensor) { total_voltage_sensor_ = total_voltage_sensor; }
  void set_current_sensor(sensor::Sensor *current_sensor) { current_sensor_ = current_sensor; }
  void set_power_sensor(sensor::Sensor *power_sensor) { power_sensor_ = power_sensor; }
  void set_charging_power_sensor(sensor::Sensor *charging_power_sensor) {
    charging_power_sensor_ = charging_power_sensor;
  }
  void set_discharging_power_sensor(sensor::Sensor *discharging_power_sensor) {
    discharging_power_sensor_ = discharging_power_sensor;
  }
  void set_capacity_remaining_sensor(sensor::Sensor *capacity_remaining_sensor) {
    capacity_remaining_sensor_ = capacity_remaining_sensor;
  }
  void set_capacity_remaining_derived_sensor(sensor::Sensor *capacity_remaining_derived_sensor) {
    capacity_remaining_derived_sensor_ = capacity_remaining_derived_sensor;
  }
  void set_temperature_sensors_sensor(sensor::Sensor *temperature_sensors_sensor) {
    temperature_sensors_sensor_ = temperature_sensors_sensor;
  }
  void set_charging_cycles_sensor(sensor::Sensor *charging_cycles_sensor) {
    charging_cycles_sensor_ = charging_cycles_sensor;
  }
  void set_total_charging_cycle_capacity_sensor(sensor::Sensor *total_charging_cycle_capacity_sensor) {
    total_charging_cycle_capacity_sensor_ = total_charging_cycle_capacity_sensor;
  }
  void set_battery_strings_sensor(sensor::Sensor *battery_strings_sensor) {
    battery_strings_sensor_ = battery_strings_sensor;
  }
  void set_errors_bitmask_sensor(sensor::Sensor *errors_bitmask_sensor) {
    errors_bitmask_sensor_ = errors_bitmask_sensor;
  }
  void set_operation_mode_bitmask_sensor(sensor::Sensor *operation_mode_bitmask_sensor) {
    operation_mode_bitmask_sensor_ = operation_mode_bitmask_sensor;
  }
  void set_total_voltage_overvoltage_protection_sensor(sensor::Sensor *total_voltage_overvoltage_protection_sensor) {
    total_voltage_overvoltage_protection_sensor_ = total_voltage_overvoltage_protection_sensor;
  }
  void set_total_voltage_undervoltage_protection_sensor(sensor::Sensor *total_voltage_undervoltage_protection_sensor) {
    total_voltage_undervoltage_protection_sensor_ = total_voltage_undervoltage_protection_sensor;
  }
  void set_cell_overvoltage_protection_sensor(sensor::Sensor *cell_overvoltage_protection_sensor) {
    cell_overvoltage_protection_sensor_ = cell_overvoltage_protection_sensor;
  }
  void set_cell_overvoltage_protection_recovery_sensor(sensor::Sensor *cell_overvoltage_protection_recovery_sensor) {
    cell_overvoltage_protection_recovery_sensor_ = cell_overvoltage_protection_recovery_sensor;
  }
  void set_cell_voltage_overvoltage_delay_sensor(sensor::Sensor *cell_voltage_overvoltage_delay_sensor) {
    cell_voltage_overvoltage_delay_sensor_ = cell_voltage_overvoltage_delay_sensor;
  }
  void set_cell_undervoltage_protection_sensor(sensor::Sensor *cell_undervoltage_protection_sensor) {
    cell_undervoltage_protection_sensor_ = cell_undervoltage_protection_sensor;
  }
  void set_cell_undervoltage_protection_recovery_sensor(sensor::Sensor *cell_undervoltage_protection_recovery_sensor) {
    cell_undervoltage_protection_recovery_sensor_ = cell_undervoltage_protection_recovery_sensor;
  }
  void set_cell_request_charge_voltage_sensor(sensor::Sensor *cell_request_charge_voltage_sensor) {
    cell_request_charge_voltage_sensor_ = cell_request_charge_voltage_sensor;
  }
  void set_cell_request_float_voltage_sensor(sensor::Sensor *cell_request_float_voltage_sensor) {
    cell_request_float_voltage_sensor_ = cell_request_float_voltage_sensor;
  }
  void set_cell_voltage_undervoltage_delay_sensor(sensor::Sensor *cell_voltage_undervoltage_delay_sensor) {
    cell_voltage_undervoltage_delay_sensor_ = cell_voltage_undervoltage_delay_sensor;
  }
  void set_cell_soc100_voltage_sensor(sensor::Sensor *cell_soc100_voltage_sensor) {
    cell_soc100_voltage_sensor_ = cell_soc100_voltage_sensor;
  }
  void set_cell_soc0_voltage_sensor(sensor::Sensor *cell_soc0_voltage_sensor) {
    cell_soc0_voltage_sensor_ = cell_soc0_voltage_sensor;
  }
  void set_cell_power_off_voltage_sensor(sensor::Sensor *cell_power_off_voltage_sensor) {
    cell_power_off_voltage_sensor_ = cell_power_off_voltage_sensor;
  }

  void set_cell_pressure_difference_protection_sensor(sensor::Sensor *cell_pressure_difference_protection_sensor) {
    cell_pressure_difference_protection_sensor_ = cell_pressure_difference_protection_sensor;
  }
  void set_discharging_overcurrent_protection_sensor(sensor::Sensor *discharging_overcurrent_protection_sensor) {
    discharging_overcurrent_protection_sensor_ = discharging_overcurrent_protection_sensor;
  }
  void set_discharging_overcurrent_delay_sensor(sensor::Sensor *discharging_overcurrent_delay_sensor) {
    discharging_overcurrent_delay_sensor_ = discharging_overcurrent_delay_sensor;
  }
  void set_charging_overcurrent_protection_sensor(sensor::Sensor *charging_overcurrent_protection_sensor) {
    charging_overcurrent_protection_sensor_ = charging_overcurrent_protection_sensor;
  }
  void set_charging_overcurrent_delay_sensor(sensor::Sensor *charging_overcurrent_delay_sensor) {
    charging_overcurrent_delay_sensor_ = charging_overcurrent_delay_sensor;
  }
  void set_balance_starting_voltage_sensor(sensor::Sensor *balance_starting_voltage_sensor) {
    balance_starting_voltage_sensor_ = balance_starting_voltage_sensor;
  }
  void set_balance_opening_pressure_difference_sensor(sensor::Sensor *balance_opening_pressure_difference_sensor) {
    balance_opening_pressure_difference_sensor_ = balance_opening_pressure_difference_sensor;
  }
  void set_power_tube_temperature_protection_sensor(sensor::Sensor *power_tube_temperature_protection_sensor) {
    power_tube_temperature_protection_sensor_ = power_tube_temperature_protection_sensor;
  }
  void set_power_tube_temperature_recovery_sensor(sensor::Sensor *power_tube_temperature_recovery_sensor) {
    power_tube_temperature_recovery_sensor_ = power_tube_temperature_recovery_sensor;
  }
  void set_temperature_sensor_temperature_protection_sensor(
      sensor::Sensor *temperature_sensor_temperature_protection_sensor) {
    temperature_sensor_temperature_protection_sensor_ = temperature_sensor_temperature_protection_sensor;
  }
  void set_temperature_sensor_temperature_recovery_sensor(
      sensor::Sensor *temperature_sensor_temperature_recovery_sensor) {
    temperature_sensor_temperature_recovery_sensor_ = temperature_sensor_temperature_recovery_sensor;
  }
  void set_temperature_sensor_temperature_difference_protection_sensor(
      sensor::Sensor *temperature_sensor_temperature_difference_protection_sensor) {
    temperature_sensor_temperature_difference_protection_sensor_ =
        temperature_sensor_temperature_difference_protection_sensor;
  }
  void set_state_of_charge_sensor(sensor::Sensor *state_of_charge_sensor) {
    state_of_charge_sensor_ = state_of_charge_sensor;
  }
  void set_charging_high_temperature_protection_sensor(sensor::Sensor *charging_high_temperature_protection_sensor) {
    charging_high_temperature_protection_sensor_ = charging_high_temperature_protection_sensor;
  }
  void set_discharging_high_temperature_protection_sensor(
      sensor::Sensor *discharging_high_temperature_protection_sensor) {
    discharging_high_temperature_protection_sensor_ = discharging_high_temperature_protection_sensor;
  }
  void set_charging_low_temperature_protection_sensor(sensor::Sensor *charging_low_temperature_protection_sensor) {
    charging_low_temperature_protection_sensor_ = charging_low_temperature_protection_sensor;
  }
  void set_charging_low_temperature_recovery_sensor(sensor::Sensor *charging_low_temperature_recovery_sensor) {
    charging_low_temperature_recovery_sensor_ = charging_low_temperature_recovery_sensor;
  }
  void set_discharging_low_temperature_protection_sensor(
      sensor::Sensor *discharging_low_temperature_protection_sensor) {
    discharging_low_temperature_protection_sensor_ = discharging_low_temperature_protection_sensor;
  }
  void set_discharging_low_temperature_recovery_sensor(sensor::Sensor *discharging_low_temperature_recovery_sensor) {
    discharging_low_temperature_recovery_sensor_ = discharging_low_temperature_recovery_sensor;
  }
  void set_total_battery_capacity_setting_sensor(sensor::Sensor *total_battery_capacity_setting_sensor) {
    total_battery_capacity_setting_sensor_ = total_battery_capacity_setting_sensor;
  }
  void set_current_calibration_sensor(sensor::Sensor *current_calibration_sensor) {
    current_calibration_sensor_ = current_calibration_sensor;
  }
  void set_device_address_sensor(sensor::Sensor *device_address_sensor) {
    device_address_sensor_ = device_address_sensor;
  }
  void set_sleep_wait_time_sensor(sensor::Sensor *sleep_wait_time_sensor) {
    sleep_wait_time_sensor_ = sleep_wait_time_sensor;
  }
  void set_alarm_low_volume_sensor(sensor::Sensor *alarm_low_volume_sensor) {
    alarm_low_volume_sensor_ = alarm_low_volume_sensor;
  }
  void set_manufacturing_date_sensor(sensor::Sensor *manufacturing_date_sensor) {
    manufacturing_date_sensor_ = manufacturing_date_sensor;
  }
  void set_total_runtime_sensor(sensor::Sensor *total_runtime_sensor) { total_runtime_sensor_ = total_runtime_sensor; }
  void set_start_current_calibration_sensor(sensor::Sensor *start_current_calibration_sensor) {
    start_current_calibration_sensor_ = start_current_calibration_sensor;
  }
  void set_actual_battery_capacity_sensor(sensor::Sensor *actual_battery_capacity_sensor) {
    actual_battery_capacity_sensor_ = actual_battery_capacity_sensor;
  }
  void set_protocol_version_sensor(sensor::Sensor *protocol_version_sensor) {
    protocol_version_sensor_ = protocol_version_sensor;
  }

  // ALARMS
  void set_alarm_wireres_binary_sensor(binary_sensor::BinarySensor *alarm_wireres_binary_sensor) {
    alarm_wireres_binary_sensor_ = alarm_wireres_binary_sensor;
  }
  void set_alarm_mosotp_binary_sensor(binary_sensor::BinarySensor *alarm_mosotp_binary_sensor) {
    alarm_mosotp_binary_sensor_ = alarm_mosotp_binary_sensor;
  }
  void set_alarm_cellquantity_binary_sensor(binary_sensor::BinarySensor *alarm_cellquantity_binary_sensor) {
    alarm_cellquantity_binary_sensor_ = alarm_cellquantity_binary_sensor;
  }
  void set_alarm_cursensorerr_binary_sensor(binary_sensor::BinarySensor *alarm_cursensorerr_binary_sensor) {
    alarm_cursensorerr_binary_sensor_ = alarm_cursensorerr_binary_sensor;
  }
  void set_alarm_cellovp_binary_sensor(binary_sensor::BinarySensor *alarm_cellovp_binary_sensor) {
    alarm_cellovp_binary_sensor_ = alarm_cellovp_binary_sensor;
  }
  void set_alarm_batovp_binary_sensor(binary_sensor::BinarySensor *alarm_batovp_binary_sensor) {
    alarm_batovp_binary_sensor_ = alarm_batovp_binary_sensor;
  }
  void set_alarm_chocp_binary_sensor(binary_sensor::BinarySensor *alarm_chocp_binary_sensor) {
    alarm_chocp_binary_sensor_ = alarm_chocp_binary_sensor;
  }
  void set_alarm_chscp_binary_sensor(binary_sensor::BinarySensor *alarm_chscp_binary_sensor) {
    alarm_chscp_binary_sensor_ = alarm_chscp_binary_sensor;
  }
  void set_alarm_chotp_binary_sensor(binary_sensor::BinarySensor *alarm_chotp_binary_sensor) {
    alarm_chotp_binary_sensor_ = alarm_chotp_binary_sensor;
  }
  void set_alarm_chutp_binary_sensor(binary_sensor::BinarySensor *alarm_chutp_binary_sensor) {
    alarm_chutp_binary_sensor_ = alarm_chutp_binary_sensor;
  }
  void set_alarm_cpuauxcommuerr_binary_sensor(binary_sensor::BinarySensor *alarm_cpuauxcommuerr_binary_sensor) {
    alarm_cpuauxcommuerr_binary_sensor_ = alarm_cpuauxcommuerr_binary_sensor;
  }
  void set_alarm_celluvp_binary_sensor(binary_sensor::BinarySensor *alarm_celluvp_binary_sensor) {
    alarm_celluvp_binary_sensor_ = alarm_celluvp_binary_sensor;
  }
  void set_alarm_batuvp_binary_sensor(binary_sensor::BinarySensor *alarm_batuvp_binary_sensor) {
    alarm_batuvp_binary_sensor_ = alarm_batuvp_binary_sensor;
  }
  void set_alarm_dchocp_binary_sensor(binary_sensor::BinarySensor *alarm_dchocp_binary_sensor) {
    alarm_dchocp_binary_sensor_ = alarm_dchocp_binary_sensor;
  }
  void set_alarm_dchscp_binary_sensor(binary_sensor::BinarySensor *alarm_dchscp_binary_sensor) {
    alarm_dchscp_binary_sensor_ = alarm_dchscp_binary_sensor;
  }
  void set_alarm_dchotp_binary_sensor(binary_sensor::BinarySensor *alarm_dchotp_binary_sensor) {
    alarm_dchotp_binary_sensor_ = alarm_dchotp_binary_sensor;
  }
  void set_alarm_chargemos_binary_sensor(binary_sensor::BinarySensor *alarm_chargemos_binary_sensor) {
    alarm_chargemos_binary_sensor_ = alarm_chargemos_binary_sensor;
  }
  void set_alarm_dischargemos_binary_sensor(binary_sensor::BinarySensor *alarm_dischargemos_binary_sensor) {
    alarm_dischargemos_binary_sensor_ = alarm_dischargemos_binary_sensor;
  }
  void set_alarm_gpsdisconneted_binary_sensor(binary_sensor::BinarySensor *alarm_gpsdisconneted_binary_sensor) {
    alarm_gpsdisconneted_binary_sensor_ = alarm_gpsdisconneted_binary_sensor;
  }
  void set_alarm_modifypwdintime_binary_sensor(binary_sensor::BinarySensor *alarm_modifypwdintime_binary_sensor) {
    alarm_modifypwdintime_binary_sensor_ = alarm_modifypwdintime_binary_sensor;
  }
  void set_alarm_dischargeonfailed_binary_sensor(binary_sensor::BinarySensor *alarm_dischargeonfailed_binary_sensor) {
    alarm_dischargeonfailed_binary_sensor_ = alarm_dischargeonfailed_binary_sensor;
  }
  void set_alarm_batteryovertemp_binary_sensor(binary_sensor::BinarySensor *alarm_batteryovertemp_binary_sensor) {
    alarm_batteryovertemp_binary_sensor_ = alarm_batteryovertemp_binary_sensor;
  }
  void set_alarm_temperaturesensoranomaly_binary_sensor(binary_sensor::BinarySensor *alarm_temperaturesensoranomaly_binary_sensor) {
    alarm_temperaturesensoranomaly_binary_sensor_ = alarm_temperaturesensoranomaly_binary_sensor;
  }
  void set_alarm_plcmoduleanomaly_binary_sensor(binary_sensor::BinarySensor *alarm_plcmoduleanomaly_binary_sensor) {
    alarm_plcmoduleanomaly_binary_sensor_ = alarm_plcmoduleanomaly_binary_sensor;
  }
  void set_alarm_mostempsensorabsent_binary_sensor(binary_sensor::BinarySensor *alarm_mostempsensorabsent_binary_sensor) {
    alarm_mostempsensorabsent_binary_sensor_ = alarm_mostempsensorabsent_binary_sensor;
  }
  void set_alarm_battempsensor1absent_binary_sensor(binary_sensor::BinarySensor *alarm_battempsensor1absent_binary_sensor) {
    alarm_battempsensor1absent_binary_sensor_ = alarm_battempsensor1absent_binary_sensor;
  }
  void set_alarm_battempsensor2absent_binary_sensor(binary_sensor::BinarySensor *alarm_battempsensor2absent_binary_sensor) {
    alarm_battempsensor2absent_binary_sensor_ = alarm_battempsensor2absent_binary_sensor;
  }
  void set_alarm_battempsensor3absent_binary_sensor(binary_sensor::BinarySensor *alarm_battempsensor3absent_binary_sensor) {
    alarm_battempsensor3absent_binary_sensor_ = alarm_battempsensor3absent_binary_sensor;
  }
  void set_alarm_battempsensor4absent_binary_sensor(binary_sensor::BinarySensor *alarm_battempsensor4absent_binary_sensor) {
    alarm_battempsensor4absent_binary_sensor_ = alarm_battempsensor4absent_binary_sensor;
  }
  void set_alarm_battempsensor5absent_binary_sensor(binary_sensor::BinarySensor *alarm_battempsensor5absent_binary_sensor) {
    alarm_battempsensor5absent_binary_sensor_ = alarm_battempsensor5absent_binary_sensor;
  }



  void set_precharging_switch(switch_::Switch *precharging_switch) { precharging_switch_ = precharging_switch; }
  void set_charging_switch(switch_::Switch *charging_switch) { charging_switch_ = charging_switch; }
  void set_discharging_switch(switch_::Switch *discharging_switch) { discharging_switch_ = discharging_switch; }
  void set_balancer_switch(switch_::Switch *balancer_switch) { balancer_switch_ = balancer_switch; }
  void set_emergency_switch(switch_::Switch *emergency_switch) { emergency_switch_ = emergency_switch; }
  void set_heating_switch(switch_::Switch *heating_switch) { heating_switch_ = heating_switch; }
  void set_display_always_on_switch(switch_::Switch *display_always_on_switch) { display_always_on_switch_ = display_always_on_switch; }
  void set_charging_float_mode_switch(switch_::Switch *charging_float_mode_switch) {
    charging_float_mode_switch_ = charging_float_mode_switch;
  }
  void set_disable_temperature_sensors_switch(switch_::Switch *disable_temperature_sensors_switch) {
    disable_temperature_sensors_switch_ = disable_temperature_sensors_switch;
  }
  void set_timed_stored_data_switch(switch_::Switch *timed_stored_data_switch) {
    timed_stored_data_switch_ = timed_stored_data_switch;
  }
  
  void set_disable_pcl_module_switch(switch_::Switch *disable_pcl_module_switch) {
    disable_pcl_module_switch_ = disable_pcl_module_switch;
  }

  void set_smart_sleep_on_switch(switch_::Switch *smart_sleep_on_switch) { smart_sleep_on_switch_ = smart_sleep_on_switch; }

  void set_errors_text_sensor(text_sensor::TextSensor *errors_text_sensor) { errors_text_sensor_ = errors_text_sensor; }
  void set_operation_mode_text_sensor(text_sensor::TextSensor *operation_mode_text_sensor) {
    operation_mode_text_sensor_ = operation_mode_text_sensor;
  }
  void set_battery_type_text_sensor(text_sensor::TextSensor *battery_type_text_sensor) {
    battery_type_text_sensor_ = battery_type_text_sensor;
  }
  void set_password_text_sensor(text_sensor::TextSensor *password_text_sensor) {
    password_text_sensor_ = password_text_sensor;
  }
  void set_device_type_text_sensor(text_sensor::TextSensor *device_type_text_sensor) {
    device_type_text_sensor_ = device_type_text_sensor;
  }
  void set_software_version_text_sensor(text_sensor::TextSensor *software_version_text_sensor) {
    software_version_text_sensor_ = software_version_text_sensor;
  }
  void set_manufacturer_text_sensor(text_sensor::TextSensor *manufacturer_text_sensor) {
    manufacturer_text_sensor_ = manufacturer_text_sensor;
  }
  void set_total_runtime_formatted_text_sensor(text_sensor::TextSensor *total_runtime_formatted_text_sensor) {
    total_runtime_formatted_text_sensor_ = total_runtime_formatted_text_sensor;
  }
  void set_balancing_current_sensor(sensor::Sensor *balancing_current_sensor) {
    balancing_current_sensor_ = balancing_current_sensor;
  }  

  void dump_config() override;

  void on_jk_rs485_sniffer_data(const uint8_t &origin_address, const uint8_t &frame_type, const std::vector<uint8_t> &data) override;

  void update() override;

 protected:
  ProtocolVersion protocol_version_{PROTOCOL_VERSION_JK02_32S};
  uint8_t address_;

  binary_sensor::BinarySensor *balancing_binary_sensor_;
  binary_sensor::BinarySensor *balancing_switch_binary_sensor_;
  binary_sensor::BinarySensor *precharging_binary_sensor_; 
  binary_sensor::BinarySensor *charging_binary_sensor_;
  binary_sensor::BinarySensor *precharging_switch_binary_sensor_;
  binary_sensor::BinarySensor *charging_switch_binary_sensor_;
  binary_sensor::BinarySensor *discharging_binary_sensor_;
  binary_sensor::BinarySensor *discharging_switch_binary_sensor_;
  binary_sensor::BinarySensor *dedicated_charger_switch_binary_sensor_;
  binary_sensor::BinarySensor *heating_binary_sensor_;

  binary_sensor::BinarySensor *online_status_binary_sensor_;
  binary_sensor::BinarySensor *balancing_status_binary_sensor_;
  binary_sensor::BinarySensor *precharging_status_binary_sensor_;  
  binary_sensor::BinarySensor *charging_status_binary_sensor_;
  binary_sensor::BinarySensor *discharging_status_binary_sensor_;
  binary_sensor::BinarySensor *heating_status_binary_sensor_;

  binary_sensor::BinarySensor *alarm_wireres_binary_sensor_;
  binary_sensor::BinarySensor *alarm_mosotp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_cellquantity_binary_sensor_;
  binary_sensor::BinarySensor *alarm_cursensorerr_binary_sensor_;
  binary_sensor::BinarySensor *alarm_cellovp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_batovp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_chocp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_chscp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_chotp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_chutp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_cpuauxcommuerr_binary_sensor_;
  binary_sensor::BinarySensor *alarm_celluvp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_batuvp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_dchocp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_dchscp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_dchotp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_chargemos_binary_sensor_;
  binary_sensor::BinarySensor *alarm_dischargemos_binary_sensor_;
  binary_sensor::BinarySensor *alarm_gpsdisconneted_binary_sensor_;
  binary_sensor::BinarySensor *alarm_modifypwdintime_binary_sensor_;
  binary_sensor::BinarySensor *alarm_dischargeonfailed_binary_sensor_;
  binary_sensor::BinarySensor *alarm_batteryovertemp_binary_sensor_;
  binary_sensor::BinarySensor *alarm_temperaturesensoranomaly_binary_sensor_;
  binary_sensor::BinarySensor *alarm_plcmoduleanomaly_binary_sensor_;
  binary_sensor::BinarySensor *alarm_mostempsensorabsent_binary_sensor_;
  binary_sensor::BinarySensor *alarm_battempsensor1absent_binary_sensor_;
  binary_sensor::BinarySensor *alarm_battempsensor2absent_binary_sensor_;
  binary_sensor::BinarySensor *alarm_battempsensor3absent_binary_sensor_;
  binary_sensor::BinarySensor *alarm_battempsensor4absent_binary_sensor_;
  binary_sensor::BinarySensor *alarm_battempsensor5absent_binary_sensor_;


  sensor::Sensor *smart_sleep_time_sensor_;
  sensor::Sensor *cell_undervoltage_protection_sensor_;  
  sensor::Sensor *cell_undervoltage_protection_recovery_sensor_;
  sensor::Sensor *cell_overvoltage_protection_sensor_; 
  sensor::Sensor *cell_overvoltage_protection_recovery_sensor_; 
  sensor::Sensor *cell_request_charge_voltage_sensor_;
  sensor::Sensor *cell_request_float_voltage_sensor_; 

  sensor::Sensor *balance_trigger_voltage_sensor_;  
  sensor::Sensor *cell_soc100_voltage_sensor_;
  sensor::Sensor *cell_soc0_voltage_sensor_;  
  sensor::Sensor *cell_power_off_voltage_sensor_;


  sensor::Sensor *max_charge_current_number_;
  sensor::Sensor *charge_ocp_delay_number_;
  sensor::Sensor *charge_ocp_recovery_delay_number_;
  sensor::Sensor *max_discharge_current_number_;  
  sensor::Sensor *discharge_ocp_delay_number_;
  sensor::Sensor *discharge_ocp_recovery_time_number_; 
  sensor::Sensor *scp_recovery_time_number_;    
  sensor::Sensor *max_balance_current_number_;    
  sensor::Sensor *total_battery_capacity_number_;  

  sensor::Sensor *balancing_sensor_; 
  sensor::Sensor *cell_count_sensor_;  
  sensor::Sensor *smart_sleep_voltage_sensor_;



  sensor::Sensor *min_cell_voltage_sensor_;
  sensor::Sensor *max_cell_voltage_sensor_;
  sensor::Sensor *min_voltage_cell_sensor_;
  sensor::Sensor *max_voltage_cell_sensor_;
  sensor::Sensor *delta_cell_voltage_sensor_;
  sensor::Sensor *average_cell_voltage_sensor_;
  sensor::Sensor *power_tube_temperature_sensor_;
  sensor::Sensor *temperature_sensor_1_sensor_;
  sensor::Sensor *temperature_sensor_2_sensor_;
  sensor::Sensor *total_voltage_sensor_;
  sensor::Sensor *current_sensor_;
  sensor::Sensor *power_sensor_;
  sensor::Sensor *charging_power_sensor_;
  sensor::Sensor *discharging_power_sensor_;
  sensor::Sensor *capacity_remaining_sensor_;
  sensor::Sensor *capacity_remaining_derived_sensor_;
  sensor::Sensor *temperature_sensors_sensor_;
  sensor::Sensor *charging_cycles_sensor_;
  sensor::Sensor *total_charging_cycle_capacity_sensor_;
  sensor::Sensor *battery_strings_sensor_;
  sensor::Sensor *errors_bitmask_sensor_;
  sensor::Sensor *operation_mode_bitmask_sensor_;
  sensor::Sensor *total_voltage_overvoltage_protection_sensor_;
  sensor::Sensor *total_voltage_undervoltage_protection_sensor_;
  sensor::Sensor *cell_voltage_overvoltage_delay_sensor_;
  sensor::Sensor *cell_voltage_undervoltage_delay_sensor_;
  sensor::Sensor *cell_pressure_difference_protection_sensor_;
  sensor::Sensor *discharging_overcurrent_protection_sensor_;
  sensor::Sensor *discharging_overcurrent_delay_sensor_;
  sensor::Sensor *charging_overcurrent_protection_sensor_;
  sensor::Sensor *charging_overcurrent_delay_sensor_;
  sensor::Sensor *balance_starting_voltage_sensor_;
  sensor::Sensor *balance_opening_pressure_difference_sensor_;
  sensor::Sensor *power_tube_temperature_protection_sensor_;
  sensor::Sensor *power_tube_temperature_recovery_sensor_;
  sensor::Sensor *temperature_sensor_temperature_protection_sensor_;
  sensor::Sensor *temperature_sensor_temperature_recovery_sensor_;
  sensor::Sensor *temperature_sensor_temperature_difference_protection_sensor_;
  sensor::Sensor *charging_high_temperature_protection_sensor_;
  sensor::Sensor *discharging_high_temperature_protection_sensor_;
  sensor::Sensor *charging_low_temperature_protection_sensor_;
  sensor::Sensor *charging_low_temperature_recovery_sensor_;
  sensor::Sensor *discharging_low_temperature_protection_sensor_;
  sensor::Sensor *discharging_low_temperature_recovery_sensor_;
  sensor::Sensor *total_battery_capacity_setting_sensor_;
 
  sensor::Sensor *charging_sensor_;
  sensor::Sensor *discharging_sensor_;
  sensor::Sensor *current_calibration_sensor_;
  sensor::Sensor *device_address_sensor_;
  sensor::Sensor *sleep_wait_time_sensor_;
  sensor::Sensor *alarm_low_volume_sensor_;
  sensor::Sensor *password_sensor_;
  sensor::Sensor *manufacturing_date_sensor_;
  sensor::Sensor *total_runtime_sensor_;
  sensor::Sensor *start_current_calibration_sensor_;
  sensor::Sensor *actual_battery_capacity_sensor_;
  sensor::Sensor *protocol_version_sensor_;

  sensor::Sensor *state_of_charge_sensor_;
  sensor::Sensor *heating_current_sensor_;
  sensor::Sensor *balancing_current_sensor_;
  sensor::Sensor *emergency_time_countdown_sensor_;

  switch_::Switch *precharging_switch_;
  switch_::Switch *charging_switch_;
  switch_::Switch *discharging_switch_;
  switch_::Switch *balancer_switch_;
  switch_::Switch *emergency_switch_;  
  switch_::Switch *heating_switch_; 
  switch_::Switch *charging_float_mode_switch_;
  switch_::Switch *disable_temperature_sensors_switch_; 
  switch_::Switch *display_always_on_switch_;   
  switch_::Switch *smart_sleep_on_switch_;
  switch_::Switch *timed_stored_data_switch_;
  switch_::Switch *disable_pcl_module_switch_;

  text_sensor::TextSensor *errors_text_sensor_;
  text_sensor::TextSensor *operation_mode_text_sensor_;
  text_sensor::TextSensor *battery_type_text_sensor_;
  text_sensor::TextSensor *password_text_sensor_;
  text_sensor::TextSensor *device_type_text_sensor_;
  text_sensor::TextSensor *software_version_text_sensor_;
  text_sensor::TextSensor *manufacturer_text_sensor_;
  text_sensor::TextSensor *total_runtime_formatted_text_sensor_;

  text_sensor::TextSensor *operation_status_text_sensor_;

//  struct Cell {
//    sensor::Sensor *cell_voltage_sensor_{nullptr};
//  } cells_[24];

    
  struct Cell {
    sensor::Sensor *cell_voltage_sensor_{nullptr};
    sensor::Sensor *cell_resistance_sensor_{nullptr};
  } cells_[32];
  struct Temperature {
    sensor::Sensor *temperature_sensor_{nullptr};
  } temperatures_[4];

  uint8_t no_response_count_{0};

  void on_status_data_(const std::vector<uint8_t> &data);
  void publish_state_(binary_sensor::BinarySensor *binary_sensor, const bool &state);
  void publish_state_(sensor::Sensor *sensor, float value);
  void publish_state_(switch_::Switch *obj, const bool &state);
  void publish_state_(text_sensor::TextSensor *text_sensor, const std::string &state);
  void publish_device_unavailable_();
  void reset_online_status_tracker_();
  void track_online_status_();

  bool status_notification_received_ = false;

  uint32_t last_cell_info_{0};
  uint32_t throttle_;
  void decode_jk02_cell_info_(const std::vector<uint8_t> &data);
  void decode_jk02_settings_(const std::vector<uint8_t> &data);
  void decode_jk04_cell_info_(const std::vector<uint8_t> &data);
  void decode_device_info_(const std::vector<uint8_t> &data);

  std::string error_bits_to_string_(uint16_t bitmask);
  std::string mode_bits_to_string_(uint16_t bitmask);

  float get_temperature_(const uint16_t value) {
    if (value > 100)
      return (float) (100 - (int16_t) value);

    return (float) value;
  };

  float get_current_(const uint16_t value, const uint8_t protocol_version) {
    float current = 0.0f;
    if (protocol_version == 0x01) {
      if ((value & 0x8000) == 0x8000) {
        current = (float) (value & 0x7FFF);
      } else {
        current = (float) (value & 0x7FFF) * -1;
      }
    }

    return current;
  };

  std::string format_total_runtime_(const uint32_t value) {
    int seconds = (int) value;
    int years = seconds / (24 * 3600 * 365);
    seconds = seconds % (24 * 3600 * 365);
    int days = seconds / (24 * 3600);
    seconds = seconds % (24 * 3600);
    int hours = seconds / 3600;
    return (years ? to_string(years) + "y " : "") + (days ? to_string(days) + "d " : "") +
           (hours ? to_string(hours) + "h" : "");
  }

  float ieee_float_(uint32_t f) {
    static_assert(sizeof(float) == sizeof f, "`float` has a weird size.");
    float ret;
    std::memcpy(&ret, &f, sizeof(float));
    return ret;
  }

  bool check_bit_(uint16_t mask, uint16_t flag) { return (mask & flag) == flag; }
};

}  // namespace jk_rs485_bms
}  // namespace esphome
