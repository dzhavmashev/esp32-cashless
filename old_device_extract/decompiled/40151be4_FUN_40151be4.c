// Function : FUN_40151be4
// Address  : 0x40151be4
// Size     : 48 bytes


short FUN_40151be4(int param_1,short param_2,short param_3)

{
  short sVar1;
  ushort uVar2;
  
  sVar1 = (*(code *)&SUB_4000ab7c)(param_2,4);
  uVar2 = sVar1 - param_2 & 0xff;
  *(ushort *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) - uVar2;
  memw();
  memw();
  return param_3 - uVar2;
}

