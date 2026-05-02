// Function : FUN_40170ddc
// Address  : 0x40170ddc
// Size     : 36 bytes


void FUN_40170ddc(int param_1,int param_2)

{
  uint uVar1;
  
  FUN_40170b1c(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 == 0) {
    uVar1 = FUN_40170dc0(param_1,*(undefined4 *)(param_2 + 4));
    uVar1 = uVar1 & 0x3fffffff | *(uint *)(param_1 + 0x1c);
  }
  *(uint *)(param_1 + 0x18) = uVar1;
  return;
}

