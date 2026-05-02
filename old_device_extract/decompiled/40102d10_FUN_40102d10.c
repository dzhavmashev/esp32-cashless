// Function : FUN_40102d10
// Address  : 0x40102d10
// Size     : 90 bytes


undefined4 FUN_40102d10(int param_1,undefined4 param_2,uint param_3,int param_4,short param_5)

{
  code *pcVar1;
  uint uVar2;
  
  memw();
  (*(code *)&SUB_4008b3d0)(param_4 + -0xe,param_2,6);
  (*(code *)&SUB_4008b3d0)(param_4 + -8,param_1 + 0x234,6);
  uVar2 = (param_3 << 8 | param_3 >> 8) & 0xffff;
  *(char *)(param_4 + -2) = (char)uVar2;
  memw();
  pcVar1 = *(code **)(param_1 + 0x2f4);
  *(char *)(param_4 + -1) = (char)(uVar2 >> 8);
  memw();
  memw();
  (*pcVar1)(param_4 + -0xe,param_5 + 0xe);
  return 0;
}

