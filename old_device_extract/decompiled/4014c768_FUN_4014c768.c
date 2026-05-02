// Function : FUN_4014c768
// Address  : 0x4014c768
// Size     : 110 bytes


undefined4 FUN_4014c768(int *param_1,undefined1 *param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  
  uVar4 = 0xffffffff;
  if (param_2 != (undefined1 *)0x0) {
    iVar3 = *param_1;
    (*(code *)&SUB_4008b530)((int)param_1 + 0x83,0,4);
    iVar7 = 0;
    *(undefined1 *)((int)param_1 + 0x83) = *param_2;
    memw();
    pcVar5 = (char *)(iVar3 + 0x1ab);
    memw();
    for (; iVar7 < (int)(uint)*(byte *)(iVar3 + 0x1aa); iVar7 = iVar7 + 1) {
      memw();
      for (puVar6 = param_2; (int)puVar6 - (int)param_2 < (int)(uint)(byte)param_2[1];
          puVar6 = puVar6 + 1) {
        cVar1 = puVar6[2];
        if (cVar1 == *pcVar5) {
          bVar2 = *(byte *)(param_1 + 0x21);
          *(byte *)(param_1 + 0x21) = bVar2 + 1;
          *(char *)((int)param_1 + bVar2 + 0x85) = cVar1;
          memw();
        }
      }
      pcVar5 = pcVar5 + 1;
    }
    uVar4 = 0;
  }
  return uVar4;
}

