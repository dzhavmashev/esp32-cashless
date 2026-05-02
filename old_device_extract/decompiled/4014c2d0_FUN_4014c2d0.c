// Function : FUN_4014c2d0
// Address  : 0x4014c2d0
// Size     : 440 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4014c2d0(int param_1,byte *param_2,uint param_3,int param_4)

{
  short sVar1;
  undefined2 uVar2;
  byte bVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 uStack_40;
  byte bStack_3f;
  undefined1 auStack_3c [6];
  undefined1 auStack_36 [6];
  undefined1 auStack_30 [48];
  
  bVar3 = 0;
  if ((*param_2 & 0xf0) == 0x80) {
    if ((param_2[1] & 3) == 3) {
      bVar3 = param_2[0x1e];
    }
    else {
      bVar3 = param_2[0x18];
    }
  }
  if ((param_3 & 0xffff) < param_4 + 0xeU) {
LAB_4014c387:
    FUN_4015fb50(param_1);
    return 0;
  }
  (*(code *)&SUB_4008b3d0)(&uStack_40,param_2);
  iVar7 = *(int *)(param_1 + 4);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffeffff;
  pcVar4 = *(char **)(iVar7 + 4);
  if ((((*pcVar4 == -0x56) && (pcVar4[1] == -0x56)) && (pcVar4[2] == '\x03')) &&
     (((pcVar4[3] == '\0' && (pcVar4[4] == '\0')) &&
      ((pcVar4[5] == '\0' &&
       ((*(short *)(pcVar4 + 6) != -0xc80 && (*(short *)(pcVar4 + 6) != 0x3781)))))))) {
    if ((char)bVar3 < '\0') {
      memw();
      FUN_40147fe4(1,0x20,2,0x3f436762);
      goto LAB_4014c387;
    }
    sVar1 = *(short *)(param_1 + 0x16);
    pcVar5 = pcVar4 + -6;
    *(char **)(iVar7 + 4) = pcVar5;
    *(short *)(param_1 + 0x16) = sVar1 + 6;
    memw();
    uVar2 = *(undefined2 *)(pcVar4 + 6);
    pcVar4[6] = (char)uVar2;
    pcVar4[7] = (char)((ushort)uVar2 >> 8);
    memw();
    memw();
  }
  else if ((((_DAT_3ffc8864 == 0) || (pcVar4[3] != '\x18')) || (pcVar4[4] != -2)) ||
          ((pcVar4[5] != '4' || (*(short *)(pcVar4 + 6) != -0x1112)))) {
    sVar1 = *(short *)(param_1 + 0x16);
    pcVar5 = pcVar4 + -0xe;
    *(char **)(iVar7 + 4) = pcVar5;
    *(short *)(param_1 + 0x16) = sVar1 + 0xe;
    memw();
  }
  else {
    pcVar5 = pcVar4 + -6;
    sVar1 = *(short *)(param_1 + 0x16);
    *(char **)(iVar7 + 4) = pcVar5;
    *(short *)(param_1 + 0x16) = sVar1 + 6;
    memw();
    uVar2 = *(undefined2 *)(pcVar4 + 6);
    pcVar4[6] = (char)uVar2;
    pcVar4[7] = (char)((ushort)uVar2 >> 8);
    memw();
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x10000;
    memw();
  }
  if ((bStack_3f & 3) == 1) {
    puVar6 = auStack_30;
  }
  else {
    if ((bStack_3f & 3) != 0) {
      if ((bStack_3f & 3) != 2) {
        memw();
        return param_1;
      }
      iVar7 = (*(code *)&SUB_4008b3d0)(pcVar5,auStack_3c,6);
      puVar6 = auStack_30;
      goto LAB_4014c485;
    }
    puVar6 = auStack_3c;
  }
  iVar7 = (*(code *)&SUB_4008b3d0)(pcVar5,puVar6,6);
  puVar6 = auStack_36;
LAB_4014c485:
  (*(code *)&SUB_4008b3d0)(iVar7 + 6,puVar6);
  return param_1;
}

