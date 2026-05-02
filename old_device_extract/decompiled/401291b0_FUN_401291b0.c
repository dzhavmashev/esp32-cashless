// Function : FUN_401291b0
// Address  : 0x401291b0
// Size     : 68 bytes


void FUN_401291b0(int param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  
  (*(code *)&SUB_4008b3d0)(param_1,param_3,8);
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_3 + 8);
  memw();
  uVar1 = *(undefined1 *)(param_3 + 9);
  *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_3 + 10);
  *(undefined1 *)(param_1 + 9) = uVar1;
  memw();
  *(char *)(param_1 + 0xb) = (char)((uint)*(undefined4 *)(param_3 + 0x18) >> 8);
  memw();
  *(char *)(param_1 + 0xc) = (char)*(undefined4 *)(param_3 + 0x18);
  memw();
  *param_2 = 0xd;
  memw();
  return;
}

