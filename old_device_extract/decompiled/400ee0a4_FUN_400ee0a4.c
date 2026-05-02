// Function : FUN_400ee0a4
// Address  : 0x400ee0a4
// Size     : 676 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400ee0a4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *****pppppuVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  char *pcVar8;
  undefined4 ****local_54 [3];
  byte bStack_45;
  undefined1 auStack_44 [16];
  undefined1 auStack_34 [16];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  bVar5 = false;
  if (iVar1 != 0) {
    FUN_400f0be8(auStack_44,param_2);
    FUN_400f0d4c(auStack_34,auStack_44);
    uVar2 = FUN_400f10f0(auStack_34," Type");
    uVar2 = FUN_400f10c0(uVar2,param_1 + 0x2c);
    uVar2 = FUN_400f10f0(uVar2,"ization");
    FUN_400f0d4c(local_54,uVar2);
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_44);
    pcVar8 = "oWait < 1";
    if (*(char *)(param_1 + 0x28) != '\0') {
      pcVar8 = "ype_t ) 0";
    }
    FUN_400f1050(local_54,pcVar8);
    FUN_400f0be8(auStack_44,"HTTP/1.");
    FUN_400f0d4c(auStack_34,auStack_44);
    uVar2 = FUN_400f10c0(auStack_34,param_1 + 0xc);
    FUN_400f0fa0(local_54,uVar2);
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_44);
    if ((*(short *)(param_1 + 0x1c) != 0x50) && (*(short *)(param_1 + 0x1c) != 0x1bb)) {
      FUN_400f106c(local_54,0x3a);
      FUN_400f0dd0(auStack_34,*(undefined2 *)(param_1 + 0x1c),10);
      FUN_400f0fa0(local_54,auStack_34);
      FUN_400f0a50(auStack_34);
    }
    FUN_400f0be8(auStack_44,"\nHost: ");
    FUN_400f0d4c(auStack_34,auStack_44);
    uVar2 = FUN_400f10c0(auStack_34,param_1 + 0x5c);
    uVar2 = FUN_400f10f0(uVar2,"Agent: ");
    FUN_400f0fa0(local_54,uVar2);
    FUN_400f0a50(auStack_34);
    FUN_400f0a50(auStack_44);
    pcVar8 = "p-alive";
    if (*(char *)(param_1 + 0x24) != '\0') {
      pcVar8 = "ction: ";
    }
    FUN_400f1050(local_54,pcVar8);
    FUN_400f1050(local_54,"ggered\r\n\r\n");
    if (*(char *)(param_1 + 0x28) == '\0') {
      FUN_400f1050(local_54,"e");
    }
    iVar7 = param_1 + 0x6c;
    iVar1 = (*(code *)&LAB_40183a7b_1)(iVar7);
    if (iVar1 != 0) {
      FUN_400f0be8(auStack_34,&DAT_3f421885);
      FUN_400f0be8(auStack_44,&DAT_3f42161d);
      FUN_400f1558(iVar7,auStack_34,auStack_44);
      FUN_400f0a50(auStack_44);
      FUN_400f0a50(auStack_34);
      FUN_400f1050(local_54,"*;q=0\r\n");
      FUN_400f0fa0(local_54,param_1 + 0x7c);
      FUN_400f1050(local_54," Type");
      FUN_400f0fa0(local_54,iVar7);
      FUN_400f1050(local_54,"ggered\r\n\r\n");
    }
    FUN_400f0d4c(auStack_34,param_1 + 0x4c);
    uVar2 = FUN_400f10f0(auStack_34,"ggered\r\n\r\n");
    FUN_400f0fa0(local_54,uVar2);
    FUN_400f0a50(auStack_34);
    piVar3 = *(int **)(param_1 + 8);
    pcVar6 = *(code **)(*piVar3 + 0xc);
    pppppuVar4 = local_54;
    if ((bStack_45 & 0x80) == 0) {
      pppppuVar4 = (undefined4 *****)local_54[0];
    }
    uVar2 = (*(code *)&LAB_40183a7b_1)(local_54);
    iVar1 = (*pcVar6)(piVar3,pppppuVar4,uVar2);
    iVar7 = (*(code *)&LAB_40183a7b_1)(local_54);
    bVar5 = iVar1 == iVar7;
    FUN_400f0a50(local_54);
  }
  memw();
  memw();
  if (iStack_24 != _DAT_3ffc5708) {
    func_0x40082ecc();
    FUN_400f0a50(auStack_34);
    do {
      FUN_400f0a50(auStack_44);
      thunk_FUN_401710d8(bVar5);
    } while( true );
  }
  return;
}

