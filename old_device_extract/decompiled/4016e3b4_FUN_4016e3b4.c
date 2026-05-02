// Function : FUN_4016e3b4
// Address  : 0x4016e3b4
// Size     : 163 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016e3b4(undefined2 param_1,short param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  
  (**(code **)(_DAT_3ffc7e64 + 0xe0))();
  (**(code **)(_DAT_3ffc7e64 + 0xf0))(param_1,DAT_3ffca5b9,(int)param_2,param_3);
  (**(code **)(_DAT_3ffc7e64 + 0xe8))(param_3);
  (**(code **)(_DAT_3ffc7e64 + 0xe4))();
  (**(code **)(_DAT_3ffc7e64 + 0xec))();
  FUN_4016e218(0);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xa4))(0x62,1,5,7,0);
  *param_4 = uVar1;
  memw();
  bVar2 = (**(code **)(_DAT_3ffc7e64 + 0x98))(0x62,1,2);
  bVar3 = (**(code **)(_DAT_3ffc7e64 + 0xa4))(0x62,1,6,3,0);
  param_4[1] = bVar2 & 0xf0 | bVar3 | 0x80;
  memw();
  return;
}

