// Function : FUN_4011fe08
// Address  : 0x4011fe08
// Size     : 41 bytes


undefined4 FUN_4011fe08(uint param_1)

{
  if (param_1 < 1000) {
    (*(code *)&SUB_40008534)();
  }
  else {
    (*(code *)&SUB_40091834)((param_1 + 999) / 1000);
  }
  return 0;
}

