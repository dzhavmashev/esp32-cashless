// Function : FUN_40125fd0
// Address  : 0x40125fd0
// Size     : 42 bytes


undefined4
FUN_40125fd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)&SUB_4008c01c)(param_4);
  uVar2 = 0xffffffff;
  if (param_1 == 0x20) {
    memw();
    uVar2 = FUN_401288ec(param_2,param_3,0,param_4,uVar1,param_5,param_6);
  }
  return uVar2;
}

