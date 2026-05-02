// Function : FUN_40154c20
// Address  : 0x40154c20
// Size     : 58 bytes


void FUN_40154c20(undefined4 param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  
  puVar7 = (undefined1 *)(param_2 + 3);
  iVar5 = 0;
  do {
    puVar1 = puVar7 + 3;
    iVar6 = iVar5 + 1;
    puVar2 = puVar7 + 2;
    puVar3 = puVar7 + 1;
    uVar4 = *puVar7;
    puVar7 = puVar7 + 7;
    FUN_4015fe04(iVar5,uVar4,*puVar3,*puVar2,*puVar1);
    iVar5 = iVar6;
  } while (iVar6 != 4);
  if (DAT_3ffc7a6c != '\0') {
    FUN_4015fe04(2,2,2,3,0x5e0);
  }
  return;
}

