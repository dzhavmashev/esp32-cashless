// Function : FUN_4011cfd8
// Address  : 0x4011cfd8
// Size     : 71 bytes


undefined4 FUN_4011cfd8(char *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined1 *)0x0) {
    (*(code *)&SUB_40094c54)("rgument",0x85,"ecv_udp","length!");
  }
  if (param_1 == "r_msg") {
    uVar1 = 0xf3;
  }
  else if (param_1 == "rr_msg") {
    uVar1 = 0xf2;
  }
  else {
    uVar2 = 0;
    if (param_1 != "err_msg") goto LAB_4011d000;
    uVar1 = 0xf1;
  }
  uVar2 = 1;
  *param_2 = uVar1;
  memw();
LAB_4011d000:
  memw();
  return uVar2;
}

