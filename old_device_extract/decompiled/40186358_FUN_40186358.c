// Function : FUN_40186358
// Address  : 0x40186358
// Size     : 22 bytes


uint FUN_40186358(uint param_1,uint param_2)

{
  return (-(param_1 ^ param_2) | param_1 ^ param_2) >> 0x1f ^ 1;
}

