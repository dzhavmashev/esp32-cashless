// Function : FUN_40186390
// Address  : 0x40186390
// Size     : 23 bytes


uint FUN_40186390(uint param_1,uint param_2,uint param_3)

{
  return (int)(-param_1 | param_1) >> 0x1f & (param_2 ^ param_3) ^ param_3;
}

