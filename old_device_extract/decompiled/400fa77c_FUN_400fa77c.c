// Function : FUN_400fa77c
// Address  : 0x400fa77c
// Size     : 271 bytes


int FUN_400fa77c(int param_1,undefined4 param_2,char param_3,byte *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  byte abStack_21 [33];
  
  iVar2 = 0x1101;
  if (*(int *)(param_1 + 100) == 1) {
    for (iVar2 = *(int *)(param_1 + 0x38); iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
      memw();
      iVar3 = (*(code *)&SUB_4008c080)(param_2,iVar2 + 8,0xf);
      if (iVar3 == 0) {
        *param_4 = *(byte *)(iVar2 + 0x18);
        memw();
        memw();
        return 0;
      }
    }
    iVar2 = 0x1102;
    if (param_3 != '\0') {
      abStack_21[0] = 1;
      memw();
      uVar6 = 1;
      uVar4 = 0;
      do {
        uVar7 = uVar4;
        bVar1 = (byte)uVar6;
        if (uVar6 == 0xff) {
          return 0x1105;
        }
        uVar4 = *(uint *)(param_1 + (uVar6 >> 5) * 4 + 0x44) >> (uVar6 & 0x1f) & 1;
        uVar6 = uVar6 + 1;
      } while (uVar4 != 0);
      if (uVar7 != 0) {
        memw();
        abStack_21[0] = bVar1;
      }
      memw();
      iVar2 = FUN_400fa29c(param_1,0,1,param_2,abStack_21);
      bVar1 = abStack_21[0];
      if (iVar2 == 0) {
        iVar3 = param_1 + (uint)(abStack_21[0] >> 5) * 4;
        *(uint *)(iVar3 + 0x44) =
             *(uint *)(iVar3 + 0x44) | 1 << 0x20 - (0x20 - (abStack_21[0] & 0x1f));
        *param_4 = abStack_21[0];
        memw();
        memw();
        puVar5 = (undefined4 *)(*(code *)&SUB_40094d60)(0x1c);
        if (puVar5 == (undefined4 *)0x0) {
          iVar2 = 0x101;
        }
        else {
          *puVar5 = 0;
          puVar5[1] = 0;
          *(byte *)(puVar5 + 6) = bVar1;
          memw();
          memw();
          (*(code *)&SUB_4008c0f8)(puVar5 + 2,param_2,0xf);
          *(undefined1 *)((int)puVar5 + 0x17) = 0;
          memw();
          memw();
          FUN_40184910(param_1 + 0x38,puVar5);
        }
      }
    }
  }
  return iVar2;
}

