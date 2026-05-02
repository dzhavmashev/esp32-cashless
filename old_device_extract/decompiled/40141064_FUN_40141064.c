// Function : FUN_40141064
// Address  : 0x40141064
// Size     : 56 bytes


undefined4 FUN_40141064(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (((param_4 & 0xffffffbf) == 0x80) || (uVar1 = 0xffffffe0, param_4 == 0x100)) {
    *(char *)(param_1 + 0x15c) = (char)(param_4 >> 3);
    memw();
    memw();
    (*(code *)&SUB_4008b3d0)(param_1 + 0x15e,param_3,param_4 >> 3 & 0xff);
    uVar1 = 0;
  }
  return uVar1;
}

