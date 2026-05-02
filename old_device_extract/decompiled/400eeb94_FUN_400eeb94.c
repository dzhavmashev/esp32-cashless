// Function : FUN_400eeb94
// Address  : 0x400eeb94
// Size     : 340 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400eeb94(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_38;
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uStack_38 = func_0x4008cd34(0);
  func_0x4008ad74(&uStack_38);
  iVar1 = func_0x4008b7b0();
  FUN_400f0d70(param_2,&DAT_3f42161d);
  iVar2 = 0;
  if (*(int **)(param_1 + 0xbc) != (int *)0x0) {
    iVar2 = 0;
    for (iVar4 = **(int **)(param_1 + 0xbc); *(int *)(*(int *)(param_1 + 0xbc) + 4) != iVar4;
        iVar4 = iVar4 + 0x68) {
      if (*(char *)(iVar4 + 0x60) == '\0') {
        if (*(char *)(iVar4 + 0x58) != '\0') {
          iVar5 = *(int *)(iVar4 + 0x54);
          goto LAB_400eebf1;
        }
LAB_400eec13:
        iVar5 = FUN_400f143c(param_1 + 0xc,iVar4 + 0x34);
        if ((-1 < iVar5) &&
           ((*(char *)(iVar4 + 0x65) == '\0' || (*(char *)(param_1 + 0x29) != '\0')))) {
          iVar2 = FUN_400f11c0(param_2,&DAT_3f42161d);
          if (iVar2 == 0) {
            FUN_400f0be8(auStack_34,"t");
            uVar3 = FUN_400f10c0(auStack_34,iVar4 + 0x14);
            uVar3 = FUN_400f10f0(uVar3,"tatus ===");
            uVar3 = FUN_400f10c0(uVar3,iVar4 + 0x24);
            FUN_400f0fa0(param_2,uVar3);
            FUN_400f0a50(auStack_34);
            iVar2 = 1;
          }
          else {
            FUN_400f0d4c(auStack_34,iVar4 + 0x14);
            uVar3 = FUN_400f10f0(auStack_34,"tatus ===");
            uVar3 = FUN_400f10c0(uVar3,iVar4 + 0x24);
            FUN_400f0d18(param_2,uVar3);
            FUN_400f0a50(auStack_34);
          }
        }
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x10) + *(int *)(iVar4 + 0x5c);
LAB_400eebf1:
        if (iVar1 <= iVar5) goto LAB_400eec13;
        FUN_400eeaf8(*(int *)(param_1 + 0xbc),iVar4);
        iVar4 = iVar4 + -0x68;
      }
    }
  }
  memw();
  memw();
  if (iStack_24 == _DAT_3ffc5708) {
    return;
  }
  func_0x40082ecc();
  do {
    FUN_400f0a50(auStack_34);
    thunk_FUN_401710d8(iVar2);
  } while( true );
}

