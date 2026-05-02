// Function : FUN_4011715c
// Address  : 0x4011715c
// Size     : 231 bytes


void FUN_4011715c(int param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  
  if (7 < *(ushort *)(param_1 + 10)) {
    pbVar5 = *(byte **)(param_1 + 4);
    iVar4 = FUN_4011dbec(param_1,0x3a,*(undefined2 *)(param_1 + 8),&DAT_3ffc83cc,&DAT_3ffc83e4);
    if (iVar4 == 0) {
      bVar1 = *pbVar5;
      if (bVar1 < 0x85) {
        if (0x81 < bVar1) {
          FUN_40118554(param_1,param_2);
          return;
        }
        if (bVar1 == 2) {
LAB_401171d9:
          FUN_40119200(param_1,param_2);
          return;
        }
        if (((bVar1 == 0x80) && (DAT_3ffc83e4 != -1)) &&
           (iVar4 = FUN_4010bbc4(0x36,*(undefined2 *)(param_1 + 8),0x280), iVar4 != 0)) {
          cVar2 = FUN_4010bf9c(iVar4,param_1);
          if (cVar2 == '\0') {
            puVar6 = *(undefined1 **)(iVar4 + 4);
            *puVar6 = 0x81;
            memw();
            uVar3 = *(undefined2 *)(iVar4 + 8);
            puVar6[2] = 0;
            puVar6[3] = 0;
            memw();
            memw();
            uVar3 = FUN_4011dbec(iVar4,0x3a,uVar3,&DAT_3ffc83e4,&DAT_3ffc83cc);
            puVar6[2] = (char)uVar3;
            memw();
            puVar6[3] = (char)((ushort)uVar3 >> 8);
            memw();
            memw();
            FUN_40117f9c(iVar4,&DAT_3ffc83e4,&DAT_3ffc83cc,0xff,0,0x3a,param_2);
            FUN_4010bb10(iVar4);
          }
          else {
            FUN_4010bb10(param_1);
            param_1 = iVar4;
          }
        }
      }
      else if ((byte)(bVar1 + 0x7a) < 4) goto LAB_401171d9;
    }
  }
  FUN_4010bb10(param_1);
  return;
}

