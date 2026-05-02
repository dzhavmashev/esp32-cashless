// Function : FUN_4015e7f0
// Address  : 0x4015e7f0
// Size     : 46 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015e7f0(void)

{
  int iVar1;
  
  if (*(int *)(_DAT_3ffc8800 + 0xe4) != 0) {
    iVar1 = *(int *)(_DAT_3ffc8800 + 0xe4) + 0x2cc;
    (**(code **)(_DAT_3ffc1a34 + 0xec))(iVar1);
    (**(code **)(_DAT_3ffc1a34 + 0xf0))(iVar1);
  }
  return 0;
}

