// Function : FUN_400ead50
// Address  : 0x400ead50
// Size     : 91 bytes


char FUN_400ead50(int param_1,char param_2)

{
  int iVar1;
  
  param_1 = param_1 + 0xb0;
  if (param_2 == '\0') {
    iVar1 = FUN_40184464(param_1);
    if (iVar1 == 4) {
      (*(code *)&LAB_40184472_2)(param_1,5);
      return '\x01';
    }
  }
  else {
    iVar1 = FUN_40184464();
    if (((iVar1 != 0) && (iVar1 = FUN_40184464(param_1), iVar1 != 7)) &&
       (iVar1 = FUN_40184464(param_1), iVar1 != 8)) {
      (*(code *)&LAB_40184472_2)(param_1,7);
      return param_2;
    }
  }
  return '\0';
}

