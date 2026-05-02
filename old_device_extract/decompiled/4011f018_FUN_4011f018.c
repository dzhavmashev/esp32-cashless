// Function : FUN_4011f018
// Address  : 0x4011f018
// Size     : 27 bytes


undefined4 FUN_4011f018(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4011efb0();
  uVar2 = 0x200000;
  if (((iVar1 != 0) && (uVar2 = 0x400000, iVar1 != 1)) && (uVar2 = 0xffffffff, iVar1 == 2)) {
    uVar2 = 0x800000;
  }
  return uVar2;
}

