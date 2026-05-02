// Function : FUN_4010affc
// Address  : 0x4010affc
// Size     : 49 bytes


void FUN_4010affc(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_4010af90(param_1 + 3U & 0xfffffffc);
  FUN_4011b020();
  if ((uVar1 != 0) && ((uVar1 & 3) != 0)) {
    (*(code *)&SUB_40094c54)("aligned",0x119,"ee_pool","_malloc");
  }
  FUN_4011b040();
  return;
}

