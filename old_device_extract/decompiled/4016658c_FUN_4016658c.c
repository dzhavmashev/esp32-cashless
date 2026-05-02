// Function : FUN_4016658c
// Address  : 0x4016658c
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016658c(char param_1,uint param_2)

{
  undefined4 *puVar1;
  
  if (param_1 == '\0') {
    puVar1 = (undefined4 *)&DAT_3ff73800;
  }
  else {
    if (param_1 != '\x01') goto LAB_401665ae;
    puVar1 = (undefined4 *)&DAT_3ff73804;
  }
  memw();
  *puVar1 = 0x30000;
LAB_401665ae:
  memw();
  memw();
  _DAT_3ff73814 = (param_2 & 0xff ^ 0xffffffff) & _DAT_3ff73814;
  memw();
  return;
}

