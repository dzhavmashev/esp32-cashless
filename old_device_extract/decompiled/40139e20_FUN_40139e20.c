// Function : FUN_40139e20
// Address  : 0x40139e20
// Size     : 42 bytes


undefined4
FUN_40139e20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint *param_5,uint param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_4018658c(param_1);
  *param_5 = uVar1;
  uVar2 = 0xffffbc00;
  if (uVar1 <= param_6) {
    memw();
    uVar2 = FUN_4013bd9c(param_1,param_7,param_8,0,param_3,param_2,param_4);
  }
  return uVar2;
}

