// Function : FUN_400fee18
// Address  : 0x400fee18
// Size     : 75 bytes


undefined4
FUN_400fee18(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_400fea98(param_2);
  iVar2 = FUN_400fe73c(puVar1,param_2);
  if ((puVar1 == (uint *)0x0) || (iVar2 < 0)) {
    uVar3 = 9;
  }
  else {
    pcVar4 = (code *)puVar1[0x15];
    if (pcVar4 != (code *)0x0) {
      if ((*puVar1 & 1) == 0) {
        uVar3 = (*pcVar4)(iVar2,param_3,param_4);
      }
      else {
        uVar3 = (*pcVar4)(puVar1[0x2e],iVar2,param_3,param_4);
      }
      goto LAB_400fee33;
    }
    uVar3 = 0x58;
  }
  *param_1 = uVar3;
  uVar3 = 0xffffffff;
LAB_400fee33:
  memw();
  return uVar3;
}

