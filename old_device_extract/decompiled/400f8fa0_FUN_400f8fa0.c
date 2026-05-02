// Function : FUN_400f8fa0
// Address  : 0x400f8fa0
// Size     : 60 bytes


undefined4 FUN_400f8fa0(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 extraout_a3;
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x1e9,"ite_raw","!= NULL");
    param_3 = extraout_a3;
  }
  uVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    uVar1 = (*(code *)&SUB_4008250c)(*param_1,param_3,param_2 + param_1[3]);
  }
  return uVar1;
}

