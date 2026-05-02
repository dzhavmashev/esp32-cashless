// Function : FUN_40115934
// Address  : 0x40115934
// Size     : 395 bytes


void FUN_40115934(int param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 local_28;
  undefined4 uStack_24;
  
  if (param_2 != 0) {
    psVar5 = *(short **)(param_1 + 4);
    if ((((*psVar5 == 0x100) && ((char)psVar5[2] == '\x06')) &&
        (*(char *)((int)psVar5 + 5) == '\x04')) && (psVar5[1] == 8)) {
      pcVar8 = (char *)0x2;
      memw();
      memw();
      memw();
      local_28 = CONCAT22(psVar5[8],CONCAT11(*(undefined1 *)((int)psVar5 + 0xf),(char)psVar5[7]));
      memw();
      psVar6 = psVar5 + 4;
      memw();
      uStack_24 = CONCAT22(psVar5[0xd],
                           CONCAT11(*(undefined1 *)((int)psVar5 + 0x19),(char)psVar5[0xc]));
      memw();
      bVar2 = false;
      if (*(int *)(param_2 + 4) != 0) {
        pcVar8 = (char *)0x1;
        bVar2 = *(int *)(param_2 + 4) == uStack_24;
        if (!bVar2) {
          pcVar8 = (char *)0x2;
        }
      }
      cVar1 = *(char *)(param_2 + 0xea);
      if (cVar1 != '\x06') {
        pcVar8 = "!= NULL";
        memw();
        (*(code *)&SUB_40094c54)("!= NULL",0x1b9,"arp_raw");
      }
      if (local_28 != 0) {
        memw();
        iVar3 = FUN_4018549c(local_28,param_2);
        if (((iVar3 == 0) && ((local_28 & 0xf0) != 0xe0)) &&
           (iVar3 = FUN_401156e0(&local_28,pcVar8,param_2), -1 < iVar3)) {
          iVar3 = iVar3 * 0x18;
          (&DAT_3ffc639c)[iVar3] = 2;
          memw();
          *(int *)(&DAT_3ffc6390 + iVar3) = param_2;
          memw();
          (*(code *)&SUB_4008b3d0)(iVar3 + 0x3ffc6394,psVar6,cVar1);
          *(undefined2 *)(&DAT_3ffc639a + iVar3) = 0;
          memw();
          while (puVar7 = *(undefined4 **)(&DAT_3ffc6388 + iVar3), puVar7 != (undefined4 *)0x0) {
            *(undefined4 *)(&DAT_3ffc6388 + iVar3) = *puVar7;
            uVar4 = puVar7[1];
            memw();
            FUN_4010b078(10);
            FUN_4011aac4(param_2,uVar4,param_2 + 0xe4,psVar6,0x800);
            FUN_4010bb10(uVar4);
          }
        }
      }
      if ((psVar5[3] == 0x100) && (bVar2)) {
        memw();
        FUN_401157ec(param_2,param_2 + 0xe4,psVar6,param_2 + 0xe4,param_2 + 4,psVar6,&local_28,2);
      }
    }
    memw();
    FUN_4010bb10(param_1);
  }
  return;
}

