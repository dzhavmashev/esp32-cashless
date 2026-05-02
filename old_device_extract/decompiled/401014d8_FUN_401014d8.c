// Function : FUN_401014d8
// Address  : 0x401014d8
// Size     : 65 bytes


undefined4 FUN_401014d8(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar3 = (code *)*param_2;
  *(undefined4 **)(param_1 + 0x24) = param_2;
  if ((pcVar3 == (code *)0x0) || (iVar2 = (*pcVar3)(param_1,param_2), iVar2 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,&PTR_s_STA_DEF_3f40e714,"ith %d\n",uVar1,&PTR_s_STA_DEF_3f40e714,param_2,iVar2);
    uVar1 = 0x5008;
  }
  memw();
  return uVar1;
}

