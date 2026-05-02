// Function : FUN_4015ff3c
// Address  : 0x4015ff3c
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015ff3c(void)

{
  undefined4 uVar1;
  code *pcVar2;
  
  FUN_40166ec8();
  pcVar2 = *(code **)(_DAT_3ffc1a34 + 8);
  uVar1 = FUN_40165f04();
  (*pcVar2)(uVar1,0,0,1);
  (**(code **)(_DAT_3ffc1a34 + 0x10))(0,0x40087e48);
  (**(code **)(_DAT_3ffc1a34 + 0x14))(1);
  return;
}

