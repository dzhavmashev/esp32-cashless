// Function : FUN_40189c54
// Address  : 0x40189c54
// Size     : 30 bytes


byte FUN_40189c54(int param_1,byte param_2)

{
  byte bVar1;
  
  bVar1 = 1;
  if (*(char *)(param_1 + 0x24) != '\0') {
    bVar1 = param_2 & (byte)(*(char *)(param_1 + 0x24) - 1U) < 2;
  }
  return bVar1;
}

