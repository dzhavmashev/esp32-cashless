// Function : FUN_4011c0dc
// Address  : 0x4011c0dc
// Size     : 37 bytes


char FUN_4011c0dc(int param_1)

{
  char cVar1;
  
  if (param_1 != 0) {
    if (((*(byte *)(param_1 + 0x34) & 8) == 0) && (cVar1 = FUN_4011c0b8(), cVar1 != '\0')) {
      return cVar1;
    }
    FUN_4011d190(param_1);
  }
  return '\0';
}

