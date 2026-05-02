// Function : FUN_4014c7dc
// Address  : 0x4014c7dc
// Size     : 58 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_4014c7dc(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xb0) == 0) {
    uVar1 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(0x80);
    *(undefined4 *)(param_1 + 0xb0) = uVar1;
  }
  if (*(int *)(param_1 + 0xb0) == 0) {
    memw();
    FUN_40147fe4(1,4,1,"");
  }
  return *(int *)(param_1 + 0xb0) != 0;
}

