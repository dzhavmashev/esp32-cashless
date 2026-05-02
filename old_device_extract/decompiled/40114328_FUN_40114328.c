// Function : FUN_40114328
// Address  : 0x40114328
// Size     : 84 bytes


uint FUN_40114328(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint in_t0;
  
  uVar1 = param_1 + 4;
  if (0x80 < uVar1) {
    uVar1 = in_t0;
    (*(code *)&SUB_40094c54)("ONS_LEN",0x70e,"_struct","ONS_LEN");
  }
  *(char *)(param_2 + param_1) = (char)((uint)param_3 >> 0x18);
  *(char *)(param_2 + (param_1 + 1U & 0xffff)) = (char)((uint)param_3 >> 0x10);
  *(char *)(param_2 + (param_1 + 2U & 0xffff)) = (char)((uint)param_3 >> 8);
  *(char *)(param_2 + (param_1 + 3U & 0xffff)) = (char)param_3;
  memw();
  memw();
  return uVar1 & 0xffff;
}

