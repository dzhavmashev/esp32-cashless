// Function : FUN_40189ca4
// Address  : 0x40189ca4
// Size     : 23 bytes


bool FUN_40189ca4(int param_1,uint param_2)

{
  return *(char *)(param_1 + (param_2 & 0xff) + 0x11) == '\x02';
}

