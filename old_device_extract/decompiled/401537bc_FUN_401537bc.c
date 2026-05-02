// Function : FUN_401537bc
// Address  : 0x401537bc
// Size     : 618 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401537bc(int param_1,int param_2,int param_3,int *param_4)

{
  undefined2 uVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint local_40;
  undefined2 uStack_3c;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined1 *puStack_24;
  
  iVar5 = *param_4;
  iStack_2c = iVar5 + 0x169;
  iStack_30 = _DAT_3ffbfc54;
  memw();
  (*(code *)&SUB_4008b530)(param_3,0,0x34);
  (*(code *)&SUB_4008b530)(param_2,0,8);
  puStack_24 = (undefined1 *)(_DAT_3ffbfc54 + 0x300);
  *(undefined2 *)(param_2 + 8) = *(undefined2 *)(_DAT_3ffbfc54 + 0x3f8);
  memw();
  memw();
  uVar1 = FUN_401523bc(param_4);
  *(int *)(param_3 + 4) = param_2 + 10;
  *(undefined1 *)(param_2 + 0xc) = 0;
  iVar7 = param_2 + 0xe;
  *(undefined2 *)(param_2 + 10) = uVar1;
  memw();
  if (((_DAT_3ffc880c & 0x8000000) == 0) && (puStack_24[0xf5] != '\x01')) {
    puStack_24 = (undefined1 *)(iStack_30 + 0x300);
    *(char *)(param_2 + 0xd) = (char)*(undefined4 *)(iStack_30 + 0x368);
    memw();
    memw();
    iVar7 = (*(code *)&SUB_4008b3d0)(iVar7,iStack_30 + 0x36c,*(undefined4 *)(iStack_30 + 0x368));
    iVar7 = iVar7 + *(int *)(puStack_24 + 0x68);
  }
  else {
    *(undefined1 *)(param_2 + 0xd) = 0;
    memw();
    memw();
  }
  FUN_40151fe8(iVar7,iStack_2c);
  puVar3 = (undefined1 *)FUN_40152018();
  *(undefined1 **)(param_3 + 0xc) = puVar3;
  if (*(int *)(iVar5 + 0x14c) == 1) {
    *puVar3 = 5;
    puVar3[1] = 6;
    puVar3[2] = 0;
    puVar3[3] = 2;
    memw();
    if (_DAT_3ffc8864 != 0) {
      puVar3[3] = 1;
    }
    puVar3[4] = 0;
    memw();
    memw();
    puStack_24 = puVar3;
    (*(code *)&SUB_4008b530)(puVar3 + 5,0,3);
    puVar3 = puStack_24 + 8;
    *(undefined2 *)(param_3 + 0x18) = 1;
    memw();
  }
  *(undefined1 **)(param_3 + 0x14) = puVar3;
  if ((DAT_3ffc89d7 == '\x01') && (DAT_3ffc89d8 != '\0')) {
    memw();
    puVar3 = (undefined1 *)FUN_4015213c(puVar3);
  }
  puVar3 = (undefined1 *)FUN_40154f9c(puVar3,&DAT_3ffc87f0);
  iStack_28 = iVar5 + 0x100;
  if ((byte)(*(char *)(iVar5 + 0x168) - 2U) < 2) {
    *(undefined1 **)(param_3 + 0x1c) = puVar3;
    *puVar3 = 0x2a;
    puVar3[1] = 1;
    memw();
    bVar6 = 2;
    if ((_DAT_3ffc880c & 0x100000) == 0) {
      bVar6 = 0;
    }
    if ((_DAT_3ffc880c & 0x200000) != 0) {
      bVar6 = bVar6 | 4;
    }
    puVar3[2] = bVar6;
    memw();
    puVar3 = puVar3 + 3;
  }
  memw();
  puVar3 = (undefined1 *)FUN_40152040(puVar3,iStack_2c);
  if (*(int *)(iVar5 + 0x150) != 0) {
    memw();
    puStack_24 = puVar3;
    iVar7 = (**(code **)(_DAT_3ffc89a4 + 0x2c))(&local_40);
    puVar3 = puStack_24;
    if (iVar7 != 0) {
      iVar7 = (*(code *)&SUB_4008b3d0)(puStack_24,iVar7,local_40 & 0xff);
      puVar3 = (undefined1 *)(iVar7 + (local_40 & 0xff));
    }
  }
  if (*(char *)(iStack_28 + 0x68) == '\x03') {
    uVar4 = FUN_4014bd38(puVar3,param_4);
    *(undefined4 *)(param_3 + 0x20) = uVar4;
    memw();
    puVar3 = (undefined1 *)FUN_4014bef8(uVar4,param_4);
  }
  if ((*(uint *)(iVar5 + 0xa4) & 0x2000) != 0) {
    puVar3 = (undefined1 *)FUN_401520b8(puVar3,0);
  }
  if (_DAT_3ffc8864 != 0) {
    local_40 = 0;
    uStack_3c = 0;
    memw();
    memw();
    puStack_24 = puVar3;
    FUN_4014eb04(1,&local_40);
    uVar4 = (*_DAT_3ffc79e4)(puStack_24,&local_40);
    uVar4 = (*_DAT_3ffc79ec)(uVar4,&local_40,iStack_30 + 0x36c,*(uint *)(iStack_30 + 0x368) & 0xff);
    uVar4 = (*_DAT_3ffc79e0)(uVar4,&local_40);
    puVar3 = (undefined1 *)(*_DAT_3ffc79e8)(uVar4,&local_40);
    if (_DAT_3ffc1a40 != 0) {
      puVar3 = (undefined1 *)(*_DAT_3ffc79f0)(0x80,puVar3,&local_40);
    }
  }
  if ((_DAT_3ffc8878 != 0) && (*(int *)(_DAT_3ffc8878 + 4) != 0)) {
    puVar3 = (undefined1 *)
             FUN_4014c140(puVar3,_DAT_3ffc8878 + 1,*(int *)(_DAT_3ffc8878 + 4),
                          *(undefined1 *)(_DAT_3ffc8878 + 8));
  }
  uVar4 = FUN_401521c0(puVar3,0);
  sVar2 = FUN_40152170(uVar4,0);
  *(short *)(param_3 + 0x1a) = sVar2 - (short)*(undefined4 *)(param_3 + 0x14);
  memw();
  *(short *)(param_1 + 0x16) =
       sVar2 - ((short)*(undefined4 *)(*(int *)(param_1 + 4) + 4) + *(short *)(param_1 + 0x14));
  memw();
  memw();
  return;
}

