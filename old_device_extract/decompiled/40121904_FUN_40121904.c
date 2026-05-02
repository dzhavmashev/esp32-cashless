// Function : FUN_40121904
// Address  : 0x40121904
// Size     : 54 bytes


void FUN_40121904(void)

{
  uint uVar1;
  
  uVar1 = FUN_4018dd58();
  if ((uVar1 & 6) == 2) {
    (*(code *)&SUB_4008de0c)(uVar1 & 0xffff0000 | uVar1 & 0xfe06 | 0x1f9);
    (*(code *)&SUB_40008534)(10);
  }
  return;
}

