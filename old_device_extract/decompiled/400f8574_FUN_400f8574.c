// Function : FUN_400f8574
// Address  : 0x400f8574
// Size     : 47 bytes


undefined4 FUN_400f8574(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_4 == '\0') || (iVar1 = (*(code *)&SUB_40083c80)(), iVar1 == 0)) {
    uVar2 = (*(code *)&SUB_40082900)(param_1,param_2,param_3);
  }
  else {
    uVar2 = (*(code *)&SUB_40081fe8)(param_1,param_2,param_3);
  }
  return uVar2;
}

