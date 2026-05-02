// Function : FUN_4017c95c
// Address  : 0x4017c95c
// Size     : 53 bytes


undefined8 FUN_4017c95c(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x3ff0000000000000;
  if (param_1 < 0x18) {
    uVar1 = *(undefined8 *)(&DAT_3f426188 + param_1 * 8);
  }
  else {
    do {
      param_1 = param_1 + -1;
      uVar1 = (*(code *)&SUB_4006358c)((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x40240000);
    } while (param_1 != 0);
  }
  return uVar1;
}

