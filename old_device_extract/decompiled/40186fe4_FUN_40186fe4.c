// Function : FUN_40186fe4
// Address  : 0x40186fe4
// Size     : 3 bytes


int FUN_40186fe4(int param_1)

{
  int unaff_a8;
  
  for (; *(int *)(unaff_a8 + 8) == param_1; unaff_a8 = *(int *)(unaff_a8 + 4)) {
    param_1 = unaff_a8;
  }
  return unaff_a8;
}

