// Function : FUN_401157ec
// Address  : 0x401157ec
// Size     : 284 bytes


undefined4
FUN_401157ec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 *param_5,undefined4 param_6,undefined1 *param_7,ushort param_8)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  pcVar7 = (char *)(uint)param_8;
  if (param_1 != 0) goto LAB_4011580d;
  pcVar7 = "!= NULL";
  uVar6 = 0x46f;
  while( true ) {
    memw();
    (*(code *)&SUB_40094c54)("!= NULL",uVar6,"_output");
LAB_4011580d:
    memw();
    iVar4 = FUN_4010bbc4(0xe,0x1c,0x280);
    if (iVar4 == 0) break;
    if (*(ushort *)(iVar4 + 10) < 0x1c) {
      pcVar7 = "E_EMPTY";
      uVar6 = 0x47b;
    }
    else {
      puVar5 = *(undefined1 **)(iVar4 + 4);
      uVar3 = FUN_40185290(pcVar7);
      puVar5[6] = (char)uVar3;
      puVar5[7] = (char)((ushort)uVar3 >> 8);
      memw();
      if (*(char *)(param_1 + 0xea) == '\x06') {
        memw();
        (*(code *)&SUB_4008b3d0)(puVar5 + 8,param_4,6);
        (*(code *)&SUB_4008b3d0)(puVar5 + 0x12,param_6,6);
        uVar1 = param_5[1];
        puVar5[0xe] = *param_5;
        memw();
        uVar2 = param_5[2];
        puVar5[0xf] = uVar1;
        memw();
        uVar1 = param_5[3];
        puVar5[0x10] = uVar2;
        puVar5[0x11] = uVar1;
        memw();
        uVar1 = param_7[1];
        puVar5[0x18] = *param_7;
        memw();
        uVar2 = param_7[2];
        puVar5[0x19] = uVar1;
        memw();
        uVar1 = param_7[3];
        puVar5[0x1a] = uVar2;
        puVar5[0x1b] = uVar1;
        memw();
        puVar5[1] = 1;
        puVar5[2] = 8;
        puVar5[4] = 6;
        memw();
        *puVar5 = 0;
        puVar5[3] = 0;
        puVar5[5] = 4;
        memw();
        memw();
        FUN_4011aac4(param_1,iVar4,param_2,param_3,0x806);
        FUN_4010bb10(iVar4);
        return 0;
      }
      pcVar7 = "arp_hdr";
      uVar6 = 0x482;
      memw();
    }
  }
  return 0xff;
}

