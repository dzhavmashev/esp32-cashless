// Function : FUN_400f9018
// Address  : 0x400f9018
// Size     : 70 bytes


undefined4 FUN_400f9018(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x20e,"on_mmap","!= NULL");
  }
  uVar1 = 0x102;
  if ((((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_3 <= (uint)param_1[4])) &&
      ((param_3 & 0xfff) == 0)) && (uVar1 = 0x102, (param_2 & 0xfff) == 0)) {
    uVar1 = (*(code *)&SUB_40082300)(*param_1,param_2 + param_1[3]);
  }
  return uVar1;
}

