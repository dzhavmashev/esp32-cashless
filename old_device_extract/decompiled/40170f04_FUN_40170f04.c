// Function : FUN_40170f04
// Address  : 0x40170f04
// Size     : 14 bytes


undefined4 FUN_40170f04(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = *(uint *)(param_1 + 0x30) >> 0x1f;
  return uVar1;
}

