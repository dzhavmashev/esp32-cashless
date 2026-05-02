// Function : FUN_40125968
// Address  : 0x40125968
// Size     : 456 bytes


int FUN_40125968(int param_1,undefined1 *param_2,int param_3,int param_4)

{
  int iVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  char *pcVar6;
  
  *param_2 = 0x30;
  param_2[3] = 0;
  param_2[2] = 1;
  memw();
  memw();
  iVar1 = FUN_40106368(2,*(undefined4 *)(param_1 + 0xc));
  if (iVar1 != 0) {
    param_2[4] = (char)((uint)iVar1 >> 0x18);
    param_2[5] = (char)((uint)iVar1 >> 0x10);
    param_2[6] = (char)((uint)iVar1 >> 8);
    param_2[7] = (char)iVar1;
    memw();
    memw();
    iVar1 = FUN_40185174(param_2 + 10,*(undefined4 *)(param_1 + 0x20));
    pcVar5 = param_2 + 10 + iVar1 * 4;
    if (iVar1 != 0) {
      param_2[9] = (char)((uint)iVar1 >> 8);
      param_2[8] = (char)iVar1;
      memw();
      cVar2 = (*(uint *)(param_1 + 4) & 1) != 0;
      if ((bool)cVar2) {
        pcVar5[2] = '\0';
        pcVar6 = pcVar5 + 6;
        pcVar5[3] = '\x0f';
        pcVar5[4] = -0x54;
        pcVar5[5] = '\x01';
        memw();
        memw();
      }
      else {
        pcVar6 = pcVar5 + 2;
      }
      if ((*(uint *)(param_1 + 4) & 2) != 0) {
        cVar2 = cVar2 + '\x01';
        *pcVar6 = '\0';
        pcVar6[1] = '\x0f';
        pcVar6[2] = -0x54;
        pcVar6[3] = '\x02';
        memw();
        pcVar6 = pcVar6 + 4;
      }
      if ((*(uint *)(param_1 + 4) & 0x80) != 0) {
        cVar2 = cVar2 + '\x01';
        *pcVar6 = '\0';
        pcVar6[1] = '\x0f';
        pcVar6[2] = -0x54;
        pcVar6[3] = '\x05';
        memw();
        pcVar6 = pcVar6 + 4;
      }
      if ((*(uint *)(param_1 + 4) & 0x100) == 0) {
        if (cVar2 == '\0') {
          return -1;
        }
      }
      else {
        cVar2 = cVar2 + '\x01';
        *pcVar6 = '\0';
        pcVar6[1] = '\x0f';
        pcVar6[2] = -0x54;
        pcVar6[3] = '\x06';
        pcVar6 = pcVar6 + 4;
      }
      pcVar5[1] = '\0';
      *pcVar5 = cVar2;
      memw();
      uVar4 = (ushort)(*(int *)(param_1 + 0x24) != 0);
      if (*(int *)(param_1 + 0x2c) != 0) {
        uVar4 = uVar4 | 0xc;
      }
      if (*(char *)(param_1 + 0x4c) != '\0') {
        uVar4 = uVar4 | 0x400;
      }
      if (*(char *)(param_1 + 0x4d) != '\0') {
        uVar4 = uVar4 | 0x800;
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        if (*(int *)(param_1 + 0x40) == 2) {
          uVar3 = 0xc0;
        }
        else {
          uVar3 = 0x80;
        }
        uVar4 = uVar4 | uVar3;
      }
      *pcVar6 = (char)uVar4;
      pcVar5 = pcVar6 + 2;
      pcVar6[1] = (char)(uVar4 >> 8);
      memw();
      if (param_4 != 0) {
        pcVar5 = pcVar6 + 0x14;
        if (param_2 + param_3 < pcVar5) {
          return -1;
        }
        pcVar6[3] = '\0';
        pcVar6[2] = '\x01';
        memw();
        memw();
        (*(code *)&SUB_4008b3d0)(pcVar6 + 4,param_4,0x10);
      }
      if (*(int *)(param_1 + 0x40) != 0) {
        if (param_2 + param_3 < pcVar5 + 6) {
          return -1;
        }
        if (param_4 == 0) {
          pcVar5[1] = '\0';
          *pcVar5 = '\0';
          pcVar5 = pcVar5 + 2;
        }
        *pcVar5 = '\0';
        pcVar5[1] = '\x0f';
        pcVar5[2] = -0x54;
        pcVar5[3] = '\x06';
        pcVar5 = pcVar5 + 4;
      }
      param_2[1] = (char)((int)pcVar5 - (int)param_2) + -2;
      memw();
      memw();
      return (int)pcVar5 - (int)param_2;
    }
  }
  return -1;
}

