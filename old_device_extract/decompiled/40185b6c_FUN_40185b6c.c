// Function : FUN_40185b6c
// Address  : 0x40185b6c
// Size     : 27 bytes


undefined4 FUN_40185b6c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar1 = 0;
  if (((2 < uVar2) && (uVar1 = 1, 4 < uVar2)) && (uVar1 = 0, uVar2 - 8 < 4)) {
    uVar1 = 1;
  }
  return uVar1;
}

