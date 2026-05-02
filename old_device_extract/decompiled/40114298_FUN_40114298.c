// Function : FUN_40114298
// Address  : 0x40114298
// Size     : 58 bytes


uint FUN_40114298(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint in_t0;
  
  uVar1 = param_1 + 2;
  if (0x80 < uVar1) {
    uVar1 = in_t0;
    (*(code *)&SUB_40094c54)("ONS_LEN",0x705,"_option","p_input");
  }
  *(char *)(param_2 + param_1) = (char)((uint)param_3 >> 8);
  *(char *)(param_2 + (param_1 + 1U & 0xffff)) = (char)param_3;
  memw();
  memw();
  return uVar1 & 0xffff;
}

